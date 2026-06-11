#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi=3.14159265358979323846;
 
int main() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    vector<ll> x(n);
    rep(i,n) x[i]=v[i];
    sort(all(x));
    ll max=x[n-1],max_sec=x[n-2];
    rep(i,n){
        if (v[i]==max){
            cout<<max_sec<<endl;
        }
        else{
            cout<<max<<endl;
        }
    }

}