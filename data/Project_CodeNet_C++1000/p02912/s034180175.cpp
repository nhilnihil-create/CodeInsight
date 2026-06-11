#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>a(n);
  for(int i=0;i<n;i++) cin >> a.at(i);
  while(m>0){
    sort(a.begin(),a.end(),greater());
    a.at(0)/=2;
    m--;
    if(m<=0) break;
    for(int i=0;i<n;i++){
      if(a.at(i)>a.at(0)){
        a.at(i)/=2;
        m--;
      }
      //cout << a.at(i) << ' ';
      if(m<=0) break;
    }
    //cout << '\n';
  }
  int64_t ans=0;
  for(int i=0;i<n;i++) ans+=a.at(i);
  cout << ans << endl;
  return 0;
}