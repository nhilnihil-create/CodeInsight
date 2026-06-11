#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll powll(ll base,ll exp) { ll res = 1; while(exp>0){ if(exp & 1)res = res * base; base = base * base; exp >>= 1; } return res;}
ll mod_pow(ll base,ll exp, ll mod) { ll res = 1; while(exp>0){ if(exp & 1)res = res * base % mod; base = base * base % mod; exp >>= 1; } return res % mod;}

int main()
{
    ll n, p; string s;
    cin >> n >> p >> s;

    if(p == 2 || p == 5) {
        ll cnt = 0;
        for(ll i = n - 1; i >= 0; i--) {
            if((s[i] - '0') % p == 0) {
                cnt += i + 1;
            }
        }
        cout << cnt << endl;
    } else {
        map<ll,ll> mp;
        ll cur = 0;
        mp[cur]++;
        for(ll i = n - 1; i >= 0; i--) {
            cur += (s[i] - '0') * mod_pow(10,n - 1 - i, p);
            cur %= p;
            mp[cur]++;
        }
        ll cnt = 0;
        for(auto i : mp) {
            cnt += (ll)i.second * (i.second - 1) / 2;
        }
        cout << cnt << endl;
    }
}