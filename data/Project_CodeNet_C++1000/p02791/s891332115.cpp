#include <bits/stdc++.h>          
using namespace std;        
typedef long long ll;       

int main() {
    ll N;
    cin >> N;
    if (N==1) {
        cout << 1 << endl;
        exit(0);
    }
    vector<ll> P(N);
    for (ll i=0; i<N; i++) {
        cin >> P[i];
    }
    ll count = 1;
    ll temp = P[0];
    for (ll i=1; i<N; i++) {
        temp = min(temp,P[i]);
        if (temp==P[i]) {
            count++;
        }
    }
    cout << count << endl;
}