#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
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
    int n,k;
    cin>>n>>k;
    int mx=(n-2)*(n-1)/2;
    if(k>mx){
        cout<<-1<<endl;
        return 0;
    }
    mx-=k;
    vector<P> ans;
    rep(i,n-1)ans.push_back(P(1,i+2));
    for(int i=n;i>1&&mx>0;i--){
        arep(j,2,i){
            ans.push_back(P(j,i));
            if(--mx==0)break;
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}