#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    string S, T;
    cin >> S >> T;
    // cin >> S;
    // cin >> T;
    ll N = S.size();
    ll count = 0;
    for (ll i=0; i<N; i++) {
        if (S[i]!=T[i]) {
            count++;
        }
    }
    cout << count << endl;
}