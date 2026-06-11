#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> i_i;
  
int H, W, M;

int main() {
  cin >> H >> W >> M;
  set<i_i> st;
  map<int, int> sumh, sumw;
  int max_h = 0, max_w = 0;
  for (int i = 0; i < M; i++) {
    int h, w;
    cin >> h >> w;
    st.insert({h, w});
    max_h = max(max_h, ++sumh[h]);
    max_w = max(max_w, ++sumw[w]);
  }
  
  vector<int> max_hs, max_ws; // 最大値の行、列番号リスト
  for (auto i = sumh.begin(); i != sumh.end(); i++) {
    if (max_h == i->second) {
	  max_hs.push_back(i->first);
    }
  }
  for (auto i = sumw.begin(); i != sumw.end(); i++) {
    if (max_w == i->second) {
	  max_ws.push_back(i->first);
    }
  }
  
  int ans = max_h + max_w - 1;
  
  // 爆破地点に対象物がなければそれが最大値
  for (auto h : max_hs) {
    for (auto w : max_ws) {
	 if (st.find({h, w}) == st.end()) {
       ++ans;
       cout << ans;
       return 0;
     }
    } 
  }
  
  cout << ans;
}