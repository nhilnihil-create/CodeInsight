#include <bits/stdc++.h>          
using namespace std;              
typedef long long ll; 

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> c(N);
    ll Red = 0;
    for (ll i=0; i<N; i++) {
        c[i] = S[i];
        if (c[i] == 'R') {
            Red++;
        }
    }
    ll White = N-Red;
    ll Red_right = 0, White_left = 0;
    for (ll i=0; i<Red; i++) {
        if (c[i] == 'W') {
            White_left++;
        }
    }
    for (ll i=Red; i<N; i++) {
        if (c[i] == 'R') {
            Red_right++;
        }
    }
    ll ans = max(Red_right,White_left);
    cout << ans << endl;
}