#include<iostream>
#include<vector>
using namespace std;

int main() {
  int H,W,K,i,j,k,l;
  cin>>H>>W>>K;
  vector<string> C(H);
  for (i=0;i<H;i++) cin>>C[i];

  int black_num,ans=0;
  for (i=0;i<(1<<H);i++) {
    for (j=0;j<(1<<W);j++) {
      black_num=0;
      for (k=0;k<H && black_num<=K;k++) {
        for (l=0;l<W && black_num<=K;l++) {
          if ((i&(1<<k))==0 && (j&(1<<l))==0 && C[k][l]=='#') black_num++;
        }
      }
      if (black_num == K) ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
