#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    string s;
    cin >> n >> s;

    vector<pair<pair<ll,ll>,ll>> x(n);
    for (ll i = 0;i < n;i++){
        if (i != 0){
            x[i] = x[i-1];
        }

        if (s[i] == 'R'){
            x[i].first.first++;
        }
        else if (s[i] == 'G'){
            x[i].first.second++;
        }
        else{
            x[i].second++;
        }
    }

    /*for (ll i = 0; i < 39; i++){
        cout << x[i].first.first << " " << x[i].first.second << " " << x[i].second << endl;
    }*/

    ll ans = 0;

    for (ll j = 1; j < n-1; j++){
        for (ll k = j+1; k < n; k++){
            //cout << j << k << endl;
            ll i = j-1;
            if (s[j] == s[k]){
                continue;
            }

            if (s[j] == 'R'){
                if (s[k] == 'G'){
                    ans += x[i].second;
                }
                else{
                    ans += x[i].first.second;
                }
            }
            else if (s[j] == 'G'){
                if (s[k] == 'R'){
                    ans += x[i].second;
                }
                else{
                    ans += x[i].first.first;
                }
            }
            else{
                if (s[k] == 'R'){
                    ans += x[i].first.second;
                }
                else{
                    ans += x[i].first.first;
                }
            }

            ll t = 2*j - k;

            if (0 <= t && t <= i && s[t] != s[j] && s[t] != s[k]){
                ans--;
                //cout << t << endl;
            }
        }
    }

    cout << ans << endl;

}