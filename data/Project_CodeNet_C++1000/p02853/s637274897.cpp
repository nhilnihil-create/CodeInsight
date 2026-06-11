#include<bits/stdc++.h>
using namespace std;
int main(){
int X,Y;
  cin>>X>>Y;
  if(X==1 && Y==1)
    cout<<1000000<<endl;
  else {
  int a=100000*max(4-X,0);
    int b=100000*max(4-Y,0);
    cout<<a+b<<endl;
  
  }
    return 0;
}