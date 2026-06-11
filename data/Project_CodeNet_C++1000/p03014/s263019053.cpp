#include <iostream>
#include <string>

#define MAX 2000
#define LRMAX 1999
#define ANSMAX 3999

using namespace std;

int light_1d(int (*a)[MAX], int l, int i, int j, int d){
  int s = 0;

  while(true){
    if(d==0){
      j++;
      if(j>l-1 || a[i][j] == 1) break;
      s++;
    }
    else if(d==1){
      j--;
      if(j<0 || a[i][j] == 1) break;
      s++;
    }
  }

  return s;
}

int light_4d(int (*a)[MAX], int (*a_flip)[MAX], int H, int W, int i, int j, int ans){
  int sum, center = 1;

  int up = light_1d(a_flip, H, j, i, 1);
  if(H-(i+1)<=ans-(center+LRMAX+up)) return 0;

  int down = light_1d(a_flip, H, j, i, 0);
  if(W<=ans-(center+up+down)) return 0;

  int left = light_1d(a, W, i, j, 1);
  if(W-(j+1)<=ans-(center+up+down+left)) return 0;

  int right = light_1d(a, W, i, j, 0);
  if((sum = center+up+down+left+right)<=ans) return 0;

  return sum;
}

int main(void){

  int H, W;
  string S;
  int a[MAX][MAX], a_flip[MAX][MAX];
  int result, ans = 0;

  cin >> H >> W;
  for(int i=0; i<H; i++){
    cin >> S;
    for(int j=0; j<W; j++){
      if(S[j]=='.') a[i][j] = 0;
      else if(S[j]=='#') a[i][j] = 1;
      a_flip[j][i] = a[i][j];
    }
  }

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(a[i][j]==1) continue;
      if((result = light_4d(a, a_flip, H, W, i, j, ans))!=0) ans = result;
      if(ans==ANSMAX) break;
    }
  }

  cout << ans << endl;

  return 0;
}
