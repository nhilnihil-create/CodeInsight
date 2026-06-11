#include<bits/stdc++.h>
using namespace std;

int x,y,z;

int main(){
cin>>x>>y>>z;
  
  swap(x,y);
  swap(x,z);
  
  cout<<x<<' '<<y<<' '<<z<<'\n';
}