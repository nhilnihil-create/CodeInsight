#include<bits/stdc++.h>
using namespace std;
int main(){
  int X,Y;
  cin>>X>>Y;
  if(((4*X-Y)%2==0&&(4*X-Y)/2<=X)&&0<=(4*X-Y)/2) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}