#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  long long multi = 1;
  vector<long long> a;
  for(int i = 0; i < n; i++){
    long long x; cin >> x;
    a.push_back(x);
    if(x == 0){
      cout << 0;
      return 0;
    }
  }
  for(int i = 0; i < n; i++){
    if(a.at(i) <=1000000000000000000/multi)
      multi *=a.at(i);
    else{
      cout << -1;
      return 0;
    }
  }
  cout << multi;
}
  