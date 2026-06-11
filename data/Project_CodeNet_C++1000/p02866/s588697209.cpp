#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

int modPow(long long a, long long n, long long p) {
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}

int main(){
    ll n;
    cin >> n;
    vll d(n,0);
    rep(i, n){
        ll a;
        cin>> a;
        if(i==0){
            if(a!=0){
                cout << 0 << endl;
                return 0;
            }
        }
        d[a]++;
    }
    ll count=1;
    ll ans=1;
    ll i=1;
    if(d[0]>1){
        cout << 0 << endl;
        return 0;
    }
    while(count!=n){
        if(d[i]==0){
            cout << 0 << endl;
            return 0;
        }
        ans*=modPow(d[i-1],d[i],998244353);
        ans%=998244353;
        count+=d[i];
        i++;
    }
    cout << ans << endl;
}