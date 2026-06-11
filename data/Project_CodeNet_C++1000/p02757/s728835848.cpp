#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  string s;
  cin>>n>>p>>s;
  if(p==2||p==5){
    int64_t a=0;
    for(int i=0;i<n;i++)
      a+=((int)(s.at(i)-'0')%p==0?i+1:0);
    cout<<a<<endl;
    return 0;
  }
  vector<int> b(p,0);
  b.at(0)=1;
  for(int i=n-1,x=0,d=1;i>=0;i--,d=d*10%p){
    x=(x+(int)(s.at(i)-'0')*d)%p;
    b.at(x)++;
  }
  int64_t a=0;
  for(int i=0;i<p;i++)
    a+=(int64_t)b.at(i)*(b.at(i)-1)/2;
  cout<<a<<endl;
}