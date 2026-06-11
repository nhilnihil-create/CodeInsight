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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    int n;cin>>n;
    vi p(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    vi idx(n);
    rep(i,n){
        idx[p[i]]=i;
    }
    set<int> s;
    ll ans=0;
    drep(x,n){
        int i=idx[x];
        ll c=0;
        s.insert(i);
        vi l(2,-1),r(2,n);
        vi ls(2),rs(2);
        {
            auto it=s.find(i);
            rep(j,2){
                if(it==s.begin()) break;
                it--;
                l[j]=*it;
            }
        }
        {
            auto it=s.find(i);
            rep(j,2){
                it++;
                if(it==s.end()) break;
                r[j]=*it;
            }
        }
        ls[0]=i-l[0];ls[1]=l[0]-l[1];
        rs[0]=r[0]-i;rs[1]=r[1]-r[0];
        c=(ll)ls[0]*rs[1]+(ll)ls[1]*rs[0];
        ans+=c*(x+1);
    }
    cout<<ans<<endl;
    return 0;
}