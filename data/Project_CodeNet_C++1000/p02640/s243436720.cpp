#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int x,y,ok=0; cin>> x >> y;
  for(int i=0; i<x; ++i){
    if(2*i + 4*(x-i) == y){++ok; break;}
  }
  for(int i=0; i<x; ++i){
    if(4*i + 2*(x-i) == y){++ok; break;}
  }
  if(ok>0){
    cout<< "Yes";
  }else{
    cout<< "No";
  }
}