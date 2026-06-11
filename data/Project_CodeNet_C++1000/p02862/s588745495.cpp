#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  if((x+y)%3!=0){
    cout<<0<<endl;
    return 0;
  }
  int k=(x+y)/3;
  x-=k;
  y-=k;
  if(x<0||y<0){
    cout<<0<<endl;
    return 0;
  }
  int p=1000000007;
  vector<int64_t> f(x+y+1,1);
  for(int i=1;i<=x+y;i++)
    f.at(i)=f.at(i-1)*i%p;
  vector<int64_t> fi(x+y+1,1);
  int q=p-2;
  vector<bool> b;
  while(q>0){
    b.push_back(q%2==1);
    q/=2;
  }
  for(int d=(int)b.size()-1;d>=0;d--){
    fi.at(x+y)=fi.at(x+y)*fi.at(x+y)%p;
    if(b.at(d))
      fi.at(x+y)=fi.at(x+y)*f.at(x+y)%p;
  }
  for(int i=x+y;i>=1;i--)
    fi.at(i-1)=fi.at(i)*i%p;
  cout<<f.at(x+y)*fi.at(x)%p*fi.at(y)%p<<endl;
}