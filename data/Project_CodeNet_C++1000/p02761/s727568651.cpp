#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,char>> a(m);
  for(int i=0;i<m;i++)
    cin >> a.at(i).first >> a.at(i).second;
  int ans = -1;
  for(int i=0;i<pow(10,n+1);i++){
    bool ok=false;
    string s = to_string(i);
    if(s.size()==n){
      ok=true;
      for(int j=0;j<m;j++){
        if(a.at(j).first>s.size()||s.at(a.at(j).first-1)!=a.at(j).second){
          ok=false;
          break;
        }
      }
    }
    if(ok){
      ans=i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}