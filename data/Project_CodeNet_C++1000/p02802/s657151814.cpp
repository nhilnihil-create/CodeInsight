#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<long long> ACcnt(n),WAcnt(n);
  for(int i=0;i<m;i++){
    int p;
    string s;
    cin>>p>>s;
    p--;
    if(ACcnt[p]==0 && s=="WA")WAcnt[p]++;
    if(ACcnt[p]==0 && s=="AC")ACcnt[p]++;
  }
  long long AC=0,WA=0;
  for(int i=0;i<n;i++){
    AC+=ACcnt[i];
    if(ACcnt[i])WA+=WAcnt[i];
  }
  cout<<AC<<' '<<WA<<endl;
  return 0;
}
