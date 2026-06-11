#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, m, x, a, c, ans;
  cin >> n >> m >> x;
  vector<int> C;
  vector<vector<int> > A(n, vector<int>(m));
  for(int i=0;i<n;i++){
    cin >> c;
    C.push_back(c);
    for(int j=0;j<m;j++){
      cin >> a;
      A[i][j] = a;
    }
  }
  ans = 10000000;
  int p, ok;
  for(int i=0;i<(1<<n);i++){
    p=0;
    ok = 0;
    vector<int> skill(m);
    for(int j=0;j<n;j++){
      if(i & (1<<j)){
        p += C[j];
        for(int k=0;k<m;k++){
          skill[k] += A[j][k];
        }
      }
    }
    for(int l=0;l<m;l++){
      if(skill[l] < x){
        ok=-1;
        break;
      }
    }
    if(ok == 0){
      if(p < ans){
        ans = p;
      }
    }
  }
  if(ans == 10000000){
    ans = -1;
    cout << ans;
  }else{
    cout << ans;
  }
}