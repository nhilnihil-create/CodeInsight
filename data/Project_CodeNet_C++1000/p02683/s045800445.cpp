#include<iostream>
#include<vector>
using namespace std;
const int INF = 12000001;

int main(){
  int n,m,x;
  cin >> n >> m >> x;
  vector<int> c(n);
  int a[12][12];
  for(int i=0;i<n;i++){
    cin >> c[i];
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  
  int ans = INF;
  for(int i=0;i<(1<<n);i++){
    int cost = 0;
    vector<int> d(m);
    for(int j=0;j<n;j++){
      if(i>>j&1){
        cost += c[j];
        for(int k=0;k<m;k++){
          d[k] += a[j][k];
        }
      }
    }
    //cout << cost << endl;
    bool ok = true;
    for(int k=0;k<m;k++){
      if(d[k] < x) ok = false;
    }
    if(ok) ans = min(ans,cost);
  }
  if(ans == INF) cout << "-1" << endl;
  else cout << ans << endl;
  //cout << INF << endl;
    
}