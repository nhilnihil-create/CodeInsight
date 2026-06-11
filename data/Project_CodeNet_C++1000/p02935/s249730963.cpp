#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double ans;
  
  cin >> N;
  vector<double> vec(N);
  for(int i=0;i<N;++i){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ans = (vec.at(0) + vec.at(1))/2;
  for(int i=2;i<N;++i){
    ans = (ans+vec.at(i))/2;
  }
  cout << ans << endl;
  return 0;
}
