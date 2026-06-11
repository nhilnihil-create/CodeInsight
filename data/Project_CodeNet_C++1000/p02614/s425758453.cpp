#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll H,W,K,i,j,count;
  ll ans = 0;
  char C[6][6],B[6][6];
  cin >> H >> W >> K;
  for(i=0;i<=H-1;i++)
      cin >> C[i];
  for(ll bith = 0;bith < (1<<H);bith++)
    for(ll bitw = 0;bitw < (1<<W);bitw++){
      count = 0;
      for(i=0;i<=H-1;i++)
        for(j=0;j<=W-1;j++)
          B[i][j] = C[i][j];
      for(i=0;i<=H-1;i++)
        for(j=0;j<=W-1;j++)
          if((bith & (1<<i)) || (bitw & (1<<j)))  B[i][j] = '.';
      for(i=0;i<=H-1;i++)
        for(j=0;j<=W-1;j++) 
          if(B[i][j] == '#') count++;
      if(count == K) ans++;
    }
  cout << ans << endl;
}