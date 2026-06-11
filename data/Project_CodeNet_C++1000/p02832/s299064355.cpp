#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    int now = 1;
    bool check = 0;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        if(A.at(i) == now) {
            now++;
            check = 1;
        }
    }
    if(!check) {
        cout << -1 << endl;
        return 0;
    }
    cout << N - now + 1 << endl;



    return 0;
}