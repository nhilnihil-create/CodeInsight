#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,count = 0;
  cin>>a>>b>>c>>d;
  while(a>0&&c>0){
    if(count%2==0){
      c = c - b;
      count++;
      }
    else{
      a = a - d;
      count++;
      }
    }
    if(a<=0)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
    }