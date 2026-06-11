#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m = 0;
    cin >> m;

    vector<ll> v(1e6 + 5, 0);
    ll n = m;
    while(n % 2 == 0) {
        n = n/2;
        v[2]++;
    }

    for(int i = 3; i < sqrt(m); i+= 2) {
        while(n % i == 0) {
            n = n /i;
            v[i]++;
        }
    }

    // for(int i = 0; i < 5; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;


    ll ans = 0; 
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != 0) {
            int temp = 1;
            while(v[i] - temp >= 0) {
                v[i] -= temp;
                temp++;
                ans++;
            }
        }
    }
    
    if(n > 2) ans++;

    cout << ans << endl;


    
    return 0;
}