#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  vector<P> m[n];
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    for(int j=0; j<a; j++){
      int x, y;
      cin >> x >> y;
      x--;
      m[i].push_back(make_pair(x, y));
    }
  }
  int c = 1<<n;
  int ans = 0;
  for(int i=1; i<c; i++){
    int tmp = 0;
    bool ok = true;
    for(int bit=0; bit<n; bit++){
      if(!ok) break;
      if(i&(1<<bit)){
        tmp++;
        if(m[bit].size()==0) continue;
        for(int j=0; j<m[bit].size(); j++){
          P p = m[bit][j];
          if((i>>p.first)&1^p.second){
            ok = false;
            break;
          }
        }
      }
    }
    if(ok){
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
