#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,k;
  cin >> h >> w >> k;

  vector<vector<int>> c(h, vector<int>(w));
  char tmp;
  int num=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> tmp;
      if(tmp=='.')c[i][j]=0;
      else {
	c[i][j]=1;
	num++;
      }
    }
  }

  if(num<k){
    cout << 0 << endl;
    return 0;
  }
  
  int ans=0;
  for(int x=0;x<pow(2,h);x++){
    for(int y=0;y<pow(2,w);y++){
      int cnt=0;
      int xflag;
      int yflag;
      int tx = x;
      for(int i=0;i<h;i++){
	if(tx/pow(2,h-i-1)>=1){
	  xflag=1;
	  tx -= pow(2,h-i-1);
	}
	else xflag=0;
	int ty = y;
	for(int j=0;j<w;j++){
	  if(ty/pow(2,w-j-1)>=1){
	    yflag=1;
	    ty -= pow(2,w-j-1);
	  }
	  else yflag=0;
	  if(xflag!=1 && yflag!=1)
	    if(c[i][j]==1)cnt++;
	}
      }
      // cout << cnt << endl;
      if(cnt==k)ans++;
    }
  }

  // cout << endl;
  // int cnt=0;
  // int xflag;
  // int yflag;
  // int tx = 3;
  // for(int i=0;i<h;i++){
  //   if(tx/pow(2,h-i-1)>=1){
  //     xflag=1;
  //     tx -= pow(2,h-i-1);
  //     cout << tx << endl;
  //   }
  //   else xflag=0;
  //   int ty = 0;
  //   for(int j=0;j<w;j++){
  //     if(ty/pow(2,w-j-1)==1){
  // 	yflag=1;
  // 	ty -= pow(2,w-j-1);
  //     }
  //     else yflag=0;
  //     if(xflag!=1 && yflag!=1)if(c[i][j]==1){cnt++; cout << yflag <<"Y ";}
  //   }
  //   cout << endl;
  // }
  // cout << cnt << endl;
  // cout << endl;

  // cout << pow(2,0) << " " << 3/pow(2,1) << endl;
  
  cout << ans <<endl;
  return 0;
}
