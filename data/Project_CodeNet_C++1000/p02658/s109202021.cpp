#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long int> vec(n);
  for (int i = 0; i < n; i++){
    long int a;
    cin >> a;
    vec.at(i) = a;
    if(vec.at(i) == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  long int ans = 1;
  for (int i = 0; i < n; i++){
    if (vec.at(i) > 1000000000000000000/ans){
      cout << -1 << endl;
      return 0;
    }else{
      ans *= vec.at(i);
    }
  }
  cout << ans << endl;
}