#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e+9+7;
int main(void){
    ll n,k;cin>>n>>k;
    vector<vector<ll>> t(n),tt(n);
    rep(i,n-1){
        int a,b;cin>>a>>b;a--;b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    queue<ll> que;
    que.push(0);
    ll res=1;
    vector<bool> used(n,false);
    while(que.size()){
        int x=que.front();que.pop();
        used[x]=true;
        ll now=k;
        tt[x].push_back(x);
        rep(i,t[x].size()){
            int y=t[x][i];
            if(used[y]) now-=tt[y].size();
            else que.push(y);
            tt[y].push_back(x);
        }
        res*=now;
        res%=mod;
        //cout<<res<<endl;
    }
    cout<<res<<endl;
}