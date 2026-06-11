  #include <bits/stdc++.h>
  using namespace std;
 
  #define vi vector<int>
  #define all(v) v.begin(),v.end()
  #define ll long long int
  #define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define D1(x) {cerr<<" [" <<#x<<": "<<x<<"]";cout << endl;}
  #define D2(x) {cerr<<" [" <<#x<<": ";for(auto it:x)cerr<<it<< " ";cerr<<"] ";cout << endl;}
 
  const ll MOD=1e9+7;
  int n,m,q;
  vector<vector<int>> v(55,vector<int> (4));
  vector<int> path;
  ll ans=0LL;
  void check(){
    ll val=0;
      for(int i=0;i<q;i++){
         if((path[v[i][1]]-path[v[i][0]])==v[i][2]){
           val+=v[i][3];
         }
      }
      ans = max(ans,val);
  }
  void dfs(int i,int cur){
     if(i>=n){
        check();
        return;
     }
       for(int j=cur;j<=m;j++){
          path.push_back(j);
          dfs(i+1,j);
          path.pop_back();
       }
  }
 
  void solve(){
     cin >> n >> m >> q;
     for(int i=0;i<q;i++){
        cin >> v[i][0] >> v[i][1]>> v[i][2]>> v[i][3];
        v[i][0]--,v[i][1]--;
     }
     
     dfs(0,1);
     cout << ans;
  }
 
 
  int main(){
    IOS
       solve();
       cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }