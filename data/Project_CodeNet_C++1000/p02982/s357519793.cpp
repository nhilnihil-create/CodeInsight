#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n,d;
  cin >> n >> d;
  int ans=0;
  vector<vector<int>> x(n,vector<int>(d));
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++){
      cin >> x.at(i).at(j);
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int sum=0;
      for(int k=0;k<d;k++){
        sum += (x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
      }
      double s;
      s=sqrt(sum);
      if(s==(int)s) ans++;
    }
  }
  
  cout << ans << endl;
  return 0;
      
}
