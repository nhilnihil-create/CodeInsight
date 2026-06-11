#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
vector<int> Zalgorithm(string s){
    vector<int> a(s.size());a[0]=s.size();
    int i=1,j=0;
    while(i<s.size()){
        while(i+j<s.size()&&s[j]==s[i+j])++j;
        a[i]=j;
        if(j==0){i++;continue;}
        int k=1;
        while(i+k<s.size()&&k+a[k]<j)a[i+k]=a[k],k++;
        i+=k;j-=k;
    }
    return a;
}

int main(){
    ll n;cin >> n;
    string s;cin >> s;
    int ans=0;
    rep(i,n){
        string S=s.substr(i);
        auto v=Zalgorithm(S);
        rep(j,v.size()){
            if(v[j]>j)v[j]=j-i;
            chmax(ans,v[j]);
        }
    }
    cout << ans <<endl;
}
