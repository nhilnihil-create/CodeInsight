#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;
P po[100010];
priority_queue<int> que; 
signed main(){
  int n,m;cin>>n>>m;
  rep(i,n){
    cin>>po[i].F>>po[i].S;
  }
  sort(po,po+n);
  int ima=0;
  int ans=0;
  for(int nok=1;nok<=m;nok++){
    while(ima<n && po[ima].F<=nok){
      que.push(po[ima].S);
      ima++;
    }
    if(!que.empty()){
      ans+=que.top();
      que.pop();
    }
  }
  cout<<ans<<endl;
    
  return 0;
}
