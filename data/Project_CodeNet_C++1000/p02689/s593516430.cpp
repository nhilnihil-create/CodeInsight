#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define F first
#define S second
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()
int n,m;
int h[200000];
int ans=0;
vector<int>vec[200000];
signed main(){
    cin>>n>>m;
    rep(i,n)cin>>h[i+1];
    rep(i,m){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    rep(i,n){
        int l=vec[i+1].size();
        bool gt=true;
        rep(j,l){
            if(h[i+1]<=h[vec[i+1][j]])gt=false;
        }
        if(gt){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

