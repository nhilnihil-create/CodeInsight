#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define DEBUG
#define PI 3.141592653589793238462643383279
 
#define _GLIBCXX_DEBUG
#ifdef DEBUG
#define s(...) show(__VA_ARGS__);
#define sl(...) show(__VA_ARGS__);cout<<endl;
#else
#define s(...)
#define sl(...)
#endif
void show() {}
template <class Head,class... Args>void show(Head t,Args... args){std::cout<<t<<" ";show(args...);}
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define REP1(i, n) for(ll i = 1; i <= n; i++)
#define REPR1(i, n) for(ll i = n; i >= 1; i--)
#define FOR1(i, m, n) for(ll i = m; i <= n; i++)
const ll INF = LLONG_MAX;
const ll MOD = 1000000007;
#define VEC(type,A,N) vector<type> A(N)
#define VECi(type,A,N,i) vector<type> A(N,i)
#define VEC2(type,A,N,M) vector<vector<type>> A(N,vector<type>(M))
#define VEC2i(type,A,N,M,i) vector<vector<type>> A(N,vector<type>(M,i))
#define ALL(v) v.begin(), v.end()
ll frac(ll k){
    int s = 1;
    for (ll i=1; i<=k; ++i)s *= i;
    return s;
}
ll gcd(ll a, ll b){
   if (a%b==0)return(b);
   else return(gcd(b, a%b));
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
ll antidiv(ll N,ll C,ll D){
    return N-floor(N/C)-floor(N/D)+floor(N/lcm(C,D));
}
vector<ll> yakusuu(ll N){
    vector<ll> ret;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ret.push_back(i);
            if (i * i != N) ret.push_back(N / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    string s;
    cin>>s;
    
    VEC(ll,a,0);
    ll t=0;char ts='R';
    REP(i,s.length()){
        if(ts=='R'&&s[i]=='R'){
            t++;
        }else if(ts=='R'&&s[i]=='L'){
            a.push_back(t);
            t=1;
            ts='L';
        }else if(ts=='L'&&s[i]=='L'){
            t++;
        }else if(ts=='L'&&s[i]=='R'){
            a.push_back(t);
            t=1;
            ts='R';
        }
    }
    a.push_back(t);
    REP(i,a.size()){
        if(abs(a[i]-a[i+1])%2==0){
            ll t=(a[i]+a[i+1])/2;
            REP(j,a[i]-1)cout<<0<<" ";
            cout<<t<<" "<<t<<" ";
            REP(j,a[i+1]-1)cout<<0<<" ";
        }else{
            ll t=(a[i]+a[i+1])/2;
            if(a[i]%2==0){
                REP(j,a[i]-1)cout<<0<<" ";
                cout<<t<<" "<<t+1<<" ";
                REP(j,a[i+1]-1)cout<<0<<" ";
            }else{
                REP(j,a[i]-1)cout<<0<<" ";
                cout<<t+1<<" "<<t<<" ";
                REP(j,a[i+1]-1)cout<<0<<" ";
            }
        }
        i++;
    }
    //cout<<fixed<<setprecision(32)<<m;
    //sort(ALL(C),[](auto& a, auto& b) {return a[2] < b[2];});
    //if(equal(D.begin(), D.end()-1, K.begin()))cout<<"Yes";else cout<<"No";
    cout<<endl;
    return 0;
}
