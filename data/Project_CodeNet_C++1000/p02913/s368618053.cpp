#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
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
ll n;
string s;
vl Zalgo(string &t){
    ll m=sz(t);
    int i=1,j=0;
    vl a(m,0);
    while(i<m){
        while(i+j<m&&t[i+j]==t[j])j++;
        a[i]=j;
        if(j==0){
            i++;
            continue;
        }
        int k=1;
        while(i+k<m&&a[k]<j-k){
            a[i+k]=a[k];
            k++;
        }
        i+=k;
        j-=k;
    }
    a[0]=m;
    return a;
}
int main(){
    cin>>n>>s;
    ll ans=0;
    for(int i=0;i<n;i++){
        string t=s.substr(i);
        auto a=Zalgo(t);
        for(ll j=0;j<sz(t);j++){
            ll len=min(a[j],j);
            chmax(ans,len);
        }
    }
    cout<<ans<<endl;
    return 0;
}