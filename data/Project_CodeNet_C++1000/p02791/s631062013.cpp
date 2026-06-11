#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    int ans = 0;
    int minP = N + 1;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        if(A.at(i) <= minP) {
            ans++;
            minP = A.at(i);
        }
    }

    cout << ans << endl;



    return 0;
}