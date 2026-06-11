#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;

const int mn=1005;
const int co=(mn*(mn-1))/2;
vector<int> idtree[co];
int dp[co];
bool calculated[co];
bool visited[co];

int dfs(int no){
    if(visited[no]){
        if(!calculated[no]){
          return -1;
        }
        return dp[no];
    }
    visited[no]=true;
    dp[no]=1;
    rep(i,idtree[no].size()){
        int re=dfs(idtree[no][i]);
        if(re==-1) return -1;
        dp[no]=max(dp[no],re+1);
    }
    calculated[no]=true;
    return dp[no];
}

int main(){
    int n; cin >> n;
    vector<vector<int> > le(n);
    vector<vector<int> > id(n,vector<int>(n));
    rep(i,n){
        rep(j,n-1){
            int a; cin >> a;
            a--;
            le[i].push_back(a);
        }
    }
    int asid=0;
    rep(i,n)rep(j,n){
        if(i<j) id[i][j]=asid++; 
    }
    
    rep(i,n)rep(j,n-1){
        int ti=i;
        if(ti>le[i][j]) swap(ti,le[i][j]);
        le[i][j]=id[ti][le[i][j]];
    }
    rep(i,n){
        for(int j=n-2; j>=1; j--){
            idtree[le[i][j-1]].push_back(le[i][j]);
        }
    }
    rep(i,(n*(n-1))/2){
        visited[i]=false;
        calculated[i]=false;
    }
    
    int ans=0;
    rep(i,(n*(n-1))/2){
      int t=dfs(i);
      if(t==-1){
        ans=-1;
        break;
      }
      ans=max(ans,t);
    }
    cout << ans << endl;
return 0;
}
