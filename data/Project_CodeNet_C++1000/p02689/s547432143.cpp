#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, m, ans;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> c;
  for(int i=0;i<n;i++){
    cin >> a[i];
    c.push_back(1);
  }
  vector<vector<int> > b(m, vector<int>(2));
  for(int i=0;i<m;i++){
    for(int j=0;j<2;j++){
      cin >> b[i][j];
      b[i][j]--;
    }
  }
  for(int i=0;i<m;i++){
    if(a[b[i][0]] < a[b[i][1]]){
      c[b[i][0]] = -1;
    }else if(a[b[i][1]] < a[b[i][0]]){
      c[b[i][1]] = -1;
    }else{
      c[b[i][0]] = c[b[i][1]] = -1;
    }
  }
  ans = 0;
  for(int i=0;i<n;i++){
    if(c[i] == 1){
      ans++;
    }
  }
  cout << ans;
}
