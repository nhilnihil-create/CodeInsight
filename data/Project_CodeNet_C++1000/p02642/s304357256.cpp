#include<bits/stdc++.h>
using namespace std;
int main(void){
  int t=0,k,n,cnt=0; cin>>n;
  multiset<int> a;
  for(int i=0; i<n; ++i){ cin>>k; a.insert(k); t=max(t,k);}
  vector<int> b(t+1,0);
  for(auto itr=a.begin(); itr!=a.end();){
    cnt=a.count(*itr);
    for(int i=1; i*(*itr)<=t; ++i) b[i*(*itr)]+=cnt;
    while(cnt--) ++itr;
  }
  int res=0;
  for(auto itr=a.begin(); itr!=a.end(); ++itr) if(b[*itr]==1) ++res;
  cout<<res;
  return 0;
}