#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  ll H,cnt=0,ans=0;
  cin >> H;
  while(H>1){
    H=H/2;
    cnt++;
  }
  
  cout << ll(pow(2,cnt+1)-1) << endl;
  return 0; 
}