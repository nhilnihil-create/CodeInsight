#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n);i>0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+5  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
using PPI=pair<P,int>;
//ll const mod=998244353;
ll const mod=1e9+7;
const ll MAX=1000005;
using vi=vector<int>;
using vl=vector<ll>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvl =vector<vector<ll>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////



int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    priority_queue<int,vi,greater<int>>red,green;
    vi p(a),q(b),r(c);
    rep(i,a)cin>>p[i];
    rep(i,b)cin>>q[i];
    rep(i,c)cin>>r[i];
    sort(rall(p));
    sort(rall(q));
    sort(rall(r));
    rep(i,x){
        red.push(p[i]);
    }
    rep(i,y){
        green.push(q[i]);
    }
    for(int x:r){
        int tr=red.top(),tg=green.top();
        if(tr<=tg&&tr<x){
            red.pop();
            red.push(x);
        }
        else if(tg<tr&&tg<x){
            green.pop();
            green.push(x);
        }
    }
    ll ans=0;
    rep(i,x){
        ans+=red.top();
        red.pop();
    }
    rep(i,y){
        ans+=green.top();
        green.pop();
    }
    cout<<ans<<endl;
    return 0;
}