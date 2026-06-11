#include <bits/stdc++.h>
using namespace std;

int main() {
int s, ans=0;
  cin>>s;
int i=0;
  while(i*500<=s){
   i++;
  }
  i--;
  int j=0;
  s=s-i*500;
  while(j*5<=s){
   j++;
  }
  j--;
  
  ans=i*1000+j*5;
  cout<<ans;
  return 0;
}