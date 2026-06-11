#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<char>>a(n,vector<char>(10));
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++)
      cin >> a.at(i).at(j);
    sort(a.at(i).begin(),a.at(i).end());
  }
  sort(a.begin(),a.end());
/*for(int i=0;i<n;i++){
    for(int j=0;j<10;j++)
      cout << a.at(i).at(j);
    cout << endl;
  } */
  int64_t ans=0,c=1;
  vector<char>b(10,'/');
  for(int i=0;i<n;i++){
    if(b==a.at(i)){
      c++;
    }else{
      ans+=c*(c-1)/2;
      c=1;
      b=a.at(i);
    }
  }
  ans+=c*(c-1)/2;
  cout << ans << endl;
  return 0;
}