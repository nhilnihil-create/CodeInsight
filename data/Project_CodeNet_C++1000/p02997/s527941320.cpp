#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int ma = (n-1)*(n-2)/2;
  if(ma<k) cout << "-1" << endl;
  else{
    vector<pair<int,int>> ans;
    for(int i=1;i<=n-1;++i) ans.push_back(make_pair(i,n));
    int cal=ma-k;
    int tmp1,tmp2;
    tmp1=1;
    tmp2=2;
    for(int j=0;j<cal;++j){
      ans.push_back(make_pair(tmp1,tmp2));
      tmp2++;
      if(tmp2==n){
        tmp1++;
        tmp2=tmp1+1;
      }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
      cout << p.first << " " << p.second << endl;
    }
  }
  return 0;
}
