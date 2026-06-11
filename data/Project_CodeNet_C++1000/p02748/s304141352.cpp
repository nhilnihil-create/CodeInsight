#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,M;
  int ans;
  int mf = 300000,mr = 300000;
  
  cin >> A >> B >> M;
  vector<int> fr(A);
  vector<int> ra(B);
  for(int i=0;i<A;++i){
    cin >> fr.at(i);
    if(fr.at(i) < mf) mf = fr.at(i);
  }
  for(int i=0;i<B;++i){
    cin >> ra.at(i);
    if(ra.at(i) < mr) mr = ra.at(i);
  }

  ans = mf + mr;
  for(int i=0;i<M;++i){
    int x,y,c;
    cin >> x >> y >> c;
    int p = fr.at(x-1) + ra.at(y-1) - c;
    if(p < ans) ans = p;
  }
  cout << ans << endl;
  return 0;
}
