#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int n,d;
  cin>>n>>d;
 
  vector<vector<int>> x(n, vector<int>(d));
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      cin>>x.at(i).at(j);
    }
  }
  
  int64_t cnt=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int64_t sum=0;
      for(int k=0;k<d;k++){
        sum+=(x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
      }
      int64_t dist = (int64_t)sqrt(sum);
      if(dist*dist==sum)
        cnt++;
    }
  }
  
  cout<<cnt<<endl;
 
  return 0;
}
 