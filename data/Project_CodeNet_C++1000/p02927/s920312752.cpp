#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  int m,d;cin>>m>>d;
  int ans = 0;
  for(int i = 20; i <= d; i++){
    if(i%10 <2) continue;
    if((i/10)*(i%10) <=m) ans++;
  }

  
 
  
 cout << ans << endl;
  return 0;
}