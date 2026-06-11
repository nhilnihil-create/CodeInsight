#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n,m,q;
int a[60],b[60],c[60],d[60];
vector<int> A;
int ans=0;

void dfs(int x){  
    if(A.size()==n){
        int tmp=0;
        rep(i,q){
            if(A[b[i]]-A[a[i]]==c[i]) tmp+=d[i];
        }
        ans=max(ans,tmp);
        return;
    }
    A.push_back(x);
    for(int i=x;i<=m;i++) dfs(i);
    A.pop_back();

}

int main(){
    cin>>n>>m>>q;
    rep(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--,b[i]--;
    }

    for(int i=1;i<=m;i++){
        A.clear();
        dfs(i);
    }

    cout<<ans<<endl;
}