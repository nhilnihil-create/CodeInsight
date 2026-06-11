#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

//
//..#..
//..#..
//##.#.
//.###.
//...#.


int main(){
  int h,w,m;
  cin >> h >> w >> m;

  map<int,int> imp, jmp;
  set<pair<int,int>>st;
  rep(i,m){
    int H, W;
    cin >> H >> W;
    st.insert({H,W});
  }

  int imx=0;
  int jmx=0;
  for(auto p : st){
    imx = max(imx,++imp[p.first]);
    jmx = max(jmx,++jmp[p.second]);
  }

  vector<int> im(0), jm(0);
  for(auto p : imp){
    if(p.second == imx) im.push_back(p.first);
  }
  for(auto p : jmp){
    if(p.second == jmx) jm.push_back(p.first);
  }

  bool flag = 0;
  for(auto i : im){
    for(auto j: jm){
      if(st.find({i,j}) == st.end()) {
        cout << imx + jmx << endl;
        return 0;
      }
    }
  }
  cout << imx + jmx - 1 << endl;
}
