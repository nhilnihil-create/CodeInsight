#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;
const int INF=1e9;

int n,m,q,ans=0;
vector<int> a,b,c,d;

void dfs(vector<int> A){
    if((int)A.size()==n+1){
        int sum=0;
        rep(i,q){
            if(A[b[i]]-A[a[i]]==c[i]) sum+=d[i];
        }
        ans=max(ans,sum);
        return;
    }
    
    A.push_back(A.back());
    while(A.back()<=m){
        dfs(A);
        A.back()++;
    }
}

int main(){
    cin>>n>>m>>q;
    a=b=c=d=vector<int>(q);
    rep(i,q) cin>>a[i]>>b[i]>>c[i]>>d[i];
    dfs(vector<int>(1,1));
    cout<<ans;
}