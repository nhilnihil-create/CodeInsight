#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
bool sosu[1000010]={1,1,0};
int main(){
  int a,b,n;

  for(int i=4;i<=1000010;i+=2)sosu[i]=true;
  for(int i=3;i<=1000010;i+=2)
    for(int j=i*3;j<=1000010;j+=i*2)sosu[j]=true;

  while(cin>>a>>b>>n,a+b+n){
    int co=0;
    while(co!=n){
      if(!sosu[a])co++;
      a+=b;
    }
    cout<<a-b<<endl;
  }
}