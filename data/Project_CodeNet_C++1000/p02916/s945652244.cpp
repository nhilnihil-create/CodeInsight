#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        cin >> B.at(i);
    }
        for(int i = 0; i < N-1; i++){
        cin >> C.at(i);
    }

    int satisfy_sum = B.at(A.at(0)-1);
    for(int i = 1; i < N; i++){
        int Bnum = A.at(i) - 1;
        satisfy_sum += B.at(Bnum);
        if( i < N && A.at(i) == A.at(i-1)+1){
            satisfy_sum += C.at(A.at(i-1)-1);
        }
        // cout << satisfy_sum << endl;
    }
    cout << satisfy_sum << endl;
}