#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 
int main(void) {
  int k, x;cin>>k>>x;
  for(int i = max(x-k+1, -1000000); i <= min(x+k-1, 1000000); i++) cout << i << " ";

  
  cout << endl;
  return 0;
}