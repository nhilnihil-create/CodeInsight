#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    V<ll> a(n,-1),b(n,-1);
    int cnt=1;
    for(int i=0;i<n;i++){
        if(s[i]=='o'){
            a[i]=cnt++;
            if(cnt>k)break;
            i+=c;
        }
    }
    cnt=k;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='o'){
            b[i]=cnt--;
            if(cnt<=0)break;
            i-=c;
        }
    }
    for(int i=0;i<n;i++){
        if(0<a[i]&&a[i]==b[i])cout<<i+1<<"\n";
    }
}