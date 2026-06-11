#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,w,i,l,m,r;
  cin>>n;
  vector<int> s(n+1);
  for(i=1;i<=n;i++){
    cin>>w;
    s.at(i)=s.at(i-1)+w;
  }
  l=0;
  r=n;
  while(r-l>1){
    m=(l+r)/2;
    if(2*s.at(m)<s.at(n)) l=m;
    else r=m;
  }
  cout<<min(s.at(n)-2*s.at(l),2*s.at(r)-s.at(n))<<endl;
}