#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>>m(n);
  for(int i=0;i<n;i++)
    cin >> m.at(i).first >> m.at(i).second;
  double ans=0,b;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        b=sqrt(pow(m.at(i).first-m.at(j).first,2)+pow(m.at(i).second-m.at(j).second,2));
        ans+=b/n;
      }
    }
  }
  cout << setprecision(9);
  cout << ans << endl;
  return 0;
}