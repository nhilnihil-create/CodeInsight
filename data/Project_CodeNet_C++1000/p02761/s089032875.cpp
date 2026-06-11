#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> ans(n, -1);
  for(int i=0; i<m; i++){
    int s, c;
    cin >> s >> c;
    s--;
    if(ans[s]!=-1 && ans[s]!=c){
      cout << -1 << endl;
      return 0;
    }
    if(s==0 && c==0 && n>1){
      cout << -1 << endl;
      return 0;
    }
    ans[s] = c;
  }
  if(n==1){
    if(ans[0]==-1) cout << 0 << endl;
    else cout << ans[0] << endl;
    return 0;
  }
  for(int i=0; i<n; i++){
    if(ans[i]==-1){
      if(i==0) cout << 1;
      else cout << 0;
    }
    else cout << ans[i];
  }
  cout << endl;
  return 0;
}
