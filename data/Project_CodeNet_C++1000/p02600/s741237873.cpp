#include<bits/stdc++.h>
using namespace std;
int solve(int x){
  if(400 <= x && x<600) return 8;
  if(600 <= x && x<800) return 7;
  if(800 <= x && x<1000) return 6;
   if(1000 <= x && x<1200) return 5;
   if(1200 <= x && x<1400) return 4;
   if(1400 <= x && x<1600) return 3;
   if(1600 <= x && x<1800) return 2;
   if(1800 <= x && x<2000) return 1;
}
int main(){
  int k=0;
  cin>>k;
  cout<<solve(k)<<'\n';
  return 0;
}