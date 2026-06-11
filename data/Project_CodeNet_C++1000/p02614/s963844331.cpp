#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
int H,W,K;

int main(){
  cin >> H >> W >> K;
  vector<vector<int> > c(H,vector<int>(W));
  int all =0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char a;
      cin >> a;
      if(a=='#') {
	all++;
	c[i][j]=1;
      }
      else c[i][j]=0;
    }
  }
  int ans =0;
  for(int bith = 0;bith<(1<<H);++bith){
    for(int bitw = 0;bitw<(1<<W);++bitw){
      int black=0;
      for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
	  if((bith & (1<<i)) && (bitw & (1<<j))){
	    black+=c[i][j];
	  }
	}
      }
      if(black==K) ans++;
    }
  }
  cout << ans << endl;
}
