//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

vector<ll>a(55),b(55),c(55),d(55);
ll n,m,q;
ll mx=0,ans=0;
void dfs(vector<ll>A){
    if(A.size()==n+1){
        mx=0;
        rep(i,q){
            if(A[b[i]]-A[a[i]]==c[i])mx+=d[i];
        }
        ans=max(ans,mx);
        return;
    }
    else{
        A.push_back(A.back());
        while(A.back()<=m){
            dfs(A);
            A.back()++;
        }
    }
}
int main(){
   cin>>n>>m>>q;
    rep(i,q)cin>>a[i]>>b[i]>>c[i]>>d[i];
    vector<ll>B(1,1);
    dfs(B);
    cout<<ans<<endl;
}






































