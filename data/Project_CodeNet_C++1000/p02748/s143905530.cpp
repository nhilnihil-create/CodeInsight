#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,M,ans=0;
  cin >> A >> B >> M;
  vector<int> a(A);
  for (int i=0;i<A;i++){
  cin >> a.at(i);
  } 
  vector<int> b(B);
  for (int i=0;i<B;i++){
  cin >> b.at(i);
  }
  
  vector<vector<int>> c(M,vector<int>(3));
  vector<int> d(M);
  for (int i = 0; i <M; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c.at(i).at(j);
    }
      d.at(i) = a.at(c.at(i).at(0)-1)+b.at(c.at(i).at(1)-1)-c.at(i).at(2);
  }
  
  sort(d.begin(),d.end());
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ans=min(d.at(0),a.at(0)+b.at(0));

  cout << ans << endl;
  
}