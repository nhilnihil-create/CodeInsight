#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
int main(void)
{
  for(;;){
    int h;
    cin >> h;
    if(!h) return 0;
    int field[16][8];
    REP(i,16) REP(j,8) field[i][j]=0;
    while(h--)
      REP(i,5) cin >> field[h][i];
    int answer=0;
    bool flag=true;
    while(flag){
      flag=false;
      REP(i,10){
	if(field[i][2]==0) continue;
	int l=2,r=2;
	while(l>0&&field[i][l-1]==field[i][2]) --l;
	while(r<4&&field[i][r+1]==field[i][2]) ++r;
	if(r-l>=2)
	  for(int j=l;j<=r;++j){
	    answer+=field[i][j];
	    field[i][j]=0;
	    flag=true;
	  }
      }
      bool fall=true;
      while(fall){
	fall=false;
	REP(i,10) REP(j,5)
	  if(field[i+1][j]&&!field[i][j]){
	    field[i][j]=field[i+1][j];
	    field[i+1][j]=0;
	    fall=true;
	  }
      }
    }
    cout << answer << endl;
  }
}