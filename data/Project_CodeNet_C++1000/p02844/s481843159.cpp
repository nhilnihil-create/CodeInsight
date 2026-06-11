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

    vector<bool> pass(1005,false);

    vector<vector<bool>> before(n, vector<bool>(10,false));
    for (ll i = 1; i < n; i++){
        before[i] = before[i-1];
        before[i][s[i-1] - '0'] = true;
    }

    vector<vector<bool>> after(n, vector<bool>(10,false));
    for (ll i = n-2; i >= 0; i--){
        after[i] = after[i+1];
        after[i][s[i+1] - '0'] = true;
    }

    /*for (ll i = 0; i < n; i++){
        for (ll j = 0; j < 10; j++){
            if (before[i][j]){
                cout << j << " ";
            }
        }
        cout << endl;
    }*/

    /*for (ll i = 0; i < n-1; i++){
        for (ll j = i+1; j < n; j++){
            for (ll k = 0;k < 10;k++){
                if (x[j][k]){
                    ll a = 100*(s[i] - '0') + 10*(s[j] - '0') + k;
                    pass[a] = true;
                }
            }
        }
    }*/

    for (ll i = 1; i < n-1; i++){
        for (ll j = 0; j < 10; j++){
            if (before[i][j]){
                for (ll k = 0; k < 10; k++){
                    if (after[i][k]){
                        ll x = 100*j + 10*(s[i] - '0') + k;
                        pass[x] = true;
                    }
                }
            }
        }
    }

    ll ans = 0;

    for (auto p : pass){
        if (p){
            ans++;
        }
    }

    /*for (ll i = 0; i < 1005; i++){
        if (pass[i]){
            cout << i << endl;
        }
    }*/

    cout << ans << endl;
}