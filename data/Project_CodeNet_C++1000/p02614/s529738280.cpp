#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int h,w,k; cin >> h >> w >> k;
  vector<string> c(h); rep(i,h) cin >> c[i];

  int black = 0;
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='#') black++;
    }
  }
  
  int ans = 0;
  
  for(int bit_h = 0;bit_h<(1<<h);bit_h++){
    for(int bit_w = 0;bit_w<(1<<w);bit_w++){
      int tmp = 0;
      vector<string> now(h,"");
      rep(i,h){
	now[i] = c[i];
      }

      for(int i = 0;i<=h;i++){
	if(bit_h & (1<<i)){
	  rep(j,w){
	    now[i][j] = 'R';
	  }
	}
      }
      /*cout << "i fin: " << bit_h << endl;
	rep(i,h) cout << now[i] << endl;*/

      for(int j = 0;j<=w;j++){
	if(bit_w & (1<<j)){
	  rep(s,h){
	    now[s][j] = 'R';
	  }
	}
      }
      
      /*cout << endl << "j fin: " << bit_w << endl;
	rep(i,h) cout << now[i] << endl;*/

      rep(i,h){
	rep(j,w){
	  if(now[i][j]=='#') tmp++;
	}
      }      
      if(tmp == k) ans++;
      /*cout << "tmp: " << tmp << endl;
	cout << "ans: " << ans << endl;*/
    }
  }

  cout << ans << endl;
  
  return 0;
}
