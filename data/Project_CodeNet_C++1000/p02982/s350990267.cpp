#include<bits/stdc++.h>
using namespace std;

int main(){
  int d,n;
  cin >> n >> d;
  vector<vector<double>>ten(n,vector<double>(d));
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++)
      cin >> ten.at(i).at(j);
  }
  double a;
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a=0;
      for(int k=0;k<d;k++){
        a+=pow(ten.at(i).at(k)-ten.at(j).at(k),2);
      }
      a=sqrt(a);
      if(a!=0&&ceil(a)==a)
        ans++;
    }
  }
  cout << ans/2 << endl;
  return 0;
}