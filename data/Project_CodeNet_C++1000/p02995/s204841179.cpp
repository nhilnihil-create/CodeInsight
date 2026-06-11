#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);
long long int combination(long long int,long long int);
long long int series_sum(long long int);

int main(){
    long long int ans,a,b,c,d;
    cin>>a>>b>>c>>d;
    ans=b-a+1;
    long long int e=0;
    e+=(b/c)-(a/c);
    if(a%c==0)e++;
    e+=(b/d)-(a/d);
    if(a%d==0)e++;
    long long int f=c*d/__gcd(c,d);
    e-=(b/f)-(a/f);
    if(a%(f)==0)e--;
    cout<<ans-e<<endl;
}
