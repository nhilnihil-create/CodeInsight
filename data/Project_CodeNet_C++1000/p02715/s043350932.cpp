#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int p=1000000007;
  vector<int64_t> e(k+1,1);
  for(int i=0;i<=k;i++){
    int x=n;
    vector<bool> b;
    while(x>0){
      b.push_back(x%2==1);
      x/=2;
    }
    for(int d=(int)b.size()-1;d>=0;d--){
      e.at(i)=e.at(i)*e.at(i)%p;
      if(b.at(d))
        e.at(i)=e.at(i)*i%p;
    }
  }
  vector<int64_t> c(k+1,0);
  int64_t s=0;
  for(int i=k;i>=1;i--){
    c.at(i)=e.at(k/i);
    for(int j=2;i*j<=k;j++)
      c.at(i)=(c.at(i)-c.at(i*j)+p)%p;
    s=(s+c.at(i)*i)%p;
  }
  cout<<s<<endl;
}