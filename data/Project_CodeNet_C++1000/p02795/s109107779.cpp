#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int h,w,n;
  cin >> h >> w >> n;
  
  int point = max(h,w);
  int select = min(h,w);
  
  for(int i=1;i<=select;i++){
    if(i*point >= n){ cout << i << endl; return 0;}
  }
  
  return 0;
}