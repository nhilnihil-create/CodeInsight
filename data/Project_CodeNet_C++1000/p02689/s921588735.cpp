#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,M;
    cin >> N >> M;
    vector<int> H(N);
    map<int,int> O;
    for (int i=0;i<N;i++) {
        cin >> H[i];
        O[i+1]=H[i];
    }
    int A,B;
    for (int i=0;i<M;i++) {
        cin >> A >> B;
        if(H[A-1] > H[B-1]) {
            if (O.count(B)) {
                O.erase(B);
            }
        }
        else if (H[A-1] < H[B-1]) {
            if (O.count(A)) {
                O.erase(A);
            }
        }
        else {
            if (O.count(B)) {
                O.erase(B);
            }
            if (O.count(A)) {
                O.erase(A);
            }
        }
    }
    cout << O.size() << endl;
}
