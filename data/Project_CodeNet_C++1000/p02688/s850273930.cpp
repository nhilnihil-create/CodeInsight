#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;
    vector<int> count(N,0);
    int d;
    int A;
    int cnt = 0;
    for(int i=0;i<K;i++) {
        cin >> d;
        for(int j=0;j<d;j++) {
            cin >> A;
            count.at(A-1)++;
        }
    }
    for(int i=0;i<N;i++) {
        if(count.at(i) == 0) {
            cnt++;
        }
    }
    cout << cnt << endl;

}