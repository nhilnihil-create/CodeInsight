#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 998244353;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> d(n);
    for (ll i = 0;i < n;i++){
        cin >> d[i];
    }

    if (d[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    sort(d.begin(), d.end());

    vector<ll> num(d[n-1] +1);

    for (ll i = 0; i < n; i++){
        num[d[i]]++;
    }

    if (num[0] > 1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;

    /*for (auto p : num){
        cout << p << endl;
    }*/

    for (ll i = 1; i < (d[n-1]+1); i++){
        if (num[i] == 0){
            cout << 0 << endl;
            return 0;
        }

        rep(j,num[i]){
            ans *= num[i-1];
            ans %= MOD;
        }
    }

    cout << ans << endl;

}