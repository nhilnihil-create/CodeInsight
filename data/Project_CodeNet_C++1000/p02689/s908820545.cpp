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
  int h[n];
  vector<bool> cnt(n, true);
  for(int i=0; i<n; i++) cin >> h[i];
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(h[a]<h[b]) cnt[a]=false;
    else if(h[a]>h[b]) cnt[b]=false;
    else{
      cnt[a]=false;
      cnt[b]=false;
    }
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    if(cnt[i]){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
