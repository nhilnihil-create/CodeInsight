#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
  vector<pair<int,int>> v;
  int n;
  cin >> n;
  int i;
  for(i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    v.emplace_back(b,a);
  }
  sort(v.begin(),v.end());
  int sum = 0;
  for(auto x : v){
    sum += x.second;
    if(sum>x.first){
      cout << "No" << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
  return 0;
}