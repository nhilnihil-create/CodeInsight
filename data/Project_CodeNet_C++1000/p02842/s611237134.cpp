#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  int n,x;
  cin>>n;
  
  x=floor(n/1.08);
  if(floor(x*1.08)==n)
    cout<<x;
  else if(floor((x+1)*1.08)==n)
    cout<<x+1;
  else
  	cout<<":(";
  
  return 0;
}