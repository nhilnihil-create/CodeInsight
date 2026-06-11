#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  int n;cin>>n;
  
  Fr(i,50000) {
    if(n == (int)((double)i*1.08)) {cout << i << endl;return 0;}
  }
  cout << ":(" << endl;
  return 0;
}