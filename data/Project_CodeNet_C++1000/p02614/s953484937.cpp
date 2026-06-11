#include <bits/stdc++.h>
using namespace std;



int main() {
  
  int H, W, K;
  scanf("%d %d %d", &H, &W, &K);
  
  vector<vector<char>> v(H, vector<char>(W));

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf(" %c", &v[i][j]);
    }
  }

  int N_Pattern=0;
  int bi, bj, S;
  for(int i=0;i<pow(2,H);i++){
    for(int j=0;j<pow(2,W);j++){

      S = 0;

      bi = i;
      for(int ii=0;ii<H;ii++){

        bj = j;
        for(int jj=0;jj<W;jj++){
          
          if(bi%2==1 && bj%2==1 && v[ii][jj]=='#'){
            S+=1;
          }
          bj/=2;
        }

        bi/=2;
      }

      if(S==K){N_Pattern++;}
      
    }
  }

  printf("%d\n", N_Pattern);

  return 0;
}


