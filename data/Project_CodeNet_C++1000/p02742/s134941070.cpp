#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  ll h,w;cin>>h>>w;
  if(h==1 ||w==1) cout << 1 << endl;
  else cout << ((h%2==0||w%2==0)? (h*w/2):(h*w/2+1)) << endl;

  return 0;
}