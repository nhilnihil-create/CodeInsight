#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;
vector<vector<int>> ans;

void fill(int cnt,vector<int> v){
    if(v.size()==1) return;
    if(v.empty()) return;
    int n=v.size();
    vector<int> r,l;
    rep(i,n){
        if(i%2) r.push_back(v[i]);
        else    l.push_back(v[i]);
    }

    for(auto rr:r){
        for(auto ll:l){
            ans[rr][ll]=cnt;
            ans[ll][rr]=cnt;
        }
    }
    fill(cnt+1,l);
    fill(cnt+1,r);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    // group数 = ceil(log2(n))
    cin>>n;
    ans=vector<vector<int>>(n,vector<int>(n));

    vector<int> v(n);
    iota(ALL(v),0);
    fill(1,v);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout<<ans[i][j];
            if(j!=n-1) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
