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

    ll n,k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }

    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    
    ll b = 0;

    for (ll i = 0; i < n-1; i++){
        for (ll j = i+1; j < n; j++){
            if (a[i] > a[j]){
                b++;
            }
        }
    }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll z = 0;

    for (ll i = 0; i < n-1; i++){
        for (ll j = i+1; j < n; j++){
            if (a[i] > a[j]){
                z++;
            }
        }
    }

    //cout << b << endl;
    //cout << z << endl;

    ll p = (k-1)*k/2;
    p %= MOD;
    p *= z;
    p %= MOD;
    ll q = b*k;
    q %= MOD;
    ll ans = (p+q)%MOD;

    //cout << ((k-1)*k*z/2 + b*k)%MOD << endl;

    cout << ans << endl;

}