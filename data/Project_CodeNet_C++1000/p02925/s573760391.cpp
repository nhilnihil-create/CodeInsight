#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int n,r[2000001]={0},d[2000001]={0};
int V,f[2000001]={0},z=0;
vector<int> G[2000001],ans;
int dfs(int x){
    if(r[x]&&!f[x]) z=1;
    if(z||r[x]) return 0;
    r[x]=1;
    for(auto i:G[x]) dfs(i);
    ans.push_back(x);
    f[x]=1;
}
void tsort(){
    rep(i,V) dfs(i+1);
    reverse(all(ans));
}
int dp[2000001]={0};
int longpass(){
    for(auto i:ans)for(auto j:G[i]) dp[j]=max(dp[j],dp[i]+1);
    return *max_element(dp+1,dp+V+1);
}
int A[1000][1000];
int main(){
    cin>>n;
    map<P,int> B;
    int p=1;
    rep(i,n)rep(j,n-1){
        cin>>A[i][j];
        int a=min(i+1,A[i][j]),b=max(i+1,A[i][j]);
        if(B[P(a,b)]==0) B[P(a,b)]=p,p++;
        A[i][j]=B[P(a,b)];
    }
    rep(i,n)rep(j,n-2){
        G[A[i][j]].push_back(A[i][j+1]);
    }
    V=n*(n-1)/2;
    tsort();
    if(z) cout<<-1;
    else cout<<longpass()+1;
    cout<<"\n";
}