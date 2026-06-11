#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>T gcd(T u,T v);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);

int main(){
    ll n,a,b,d1,d2;
    cin>>n>>a>>b;
    ll ans;
    if((b-a)%2==0)ans=(b-a)/2;
    else{
        d1=a-1;
        d2=n-b;
        ans=min(d1,d2)+1+(b-a-1)/2;
    }
    cout<<ans<<endl;
}