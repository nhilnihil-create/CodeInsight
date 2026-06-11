#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> dp(n,INT_MAX);
  while(n--){
    int in;
    cin >> in;
    *lower_bound(dp.begin(), dp.end(), in) = in;
  }
  cout << lower_bound(dp.begin(), dp.end(), INT_MAX)-dp.begin() << endl;
  return 0;
}