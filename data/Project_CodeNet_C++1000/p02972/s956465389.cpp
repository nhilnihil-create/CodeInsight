#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i=1;i<n+1;i++){
    cin >> a.at(i);
  }
  
  vector<int> b(n+1,0);
  for(int i=n;i>0;i--){
    int sum=0;
    for(int j=i*2;j<n+1;j+=i){
      sum ^= b.at(j);
    }
    b.at(i) = a.at(i)^sum;
  }
  
  vector<int> ans;
  
  for(int i=1;i<n+1;i++){
    if(b.at(i) == 1){
      ans.push_back(i);
    }
  }
  
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++){
    cout << ans.at(i) << " ";
  }
  cout << endl;
  
  return(0);
}