#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll n = s.size() +1;
    vector<ll> x(n,0);
    
    for (ll i = 0; i < n; i++){
        if (i == 0){
            if (s[0] == '<'){
                x[0] = max(0LL,x[0]);
                x[1] = max(1LL,x[1]);
                ll t = 1;
                ll c = 2;
                while (s[t] == '<' && t <= n-2){
                    x[t+1] = max(c,x[t+1]);
                    c++;
                    t++;
                }
            }
            continue;
        }
        if (i == n-1){
            if (s[n-2] == '>'){
                x[n-1] = max(0LL,x[n-1]);
                x[n-2] = max(1LL,x[n-2]);
                ll t = n-3;
                ll c = 2;
                while (s[t] == '>' && t >= 0){
                    x[t] = max(c,x[t]);
                    c++;
                    t--;
                }
            }
            break;
        }
        if (s[i-1] == '>' && s[i] == '<'){
            x[i+1] = max(1LL,x[i+1]);
            x[i] = max(0LL,x[i]);
            x[i-1] = max(1LL,x[i-1]);
            ll t = i-2;
            ll c = 2;
            while (s[t] == '>' && t >= 0){
                x[t] = max(c, x[t]);
                c++;
                t--;
            }
            t = i+1;
            c = 2;
            while (s[t] == '<' && t <= n-2){
                x[t+1] = max(c,x[t+1]);
                c++;
                t++;
            }
        }
        
    }

    /*for (ll i = 0; i < n; i++){
        cout << x[i] << endl;
    }*/

    ll ans = 0;
    for (ll i = 0; i < n; i++){
        ans += x[i];
    }

    cout << ans << endl;

}