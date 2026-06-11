#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair

int main(){
  int H, W, m;
  cin >> H >> W >> m;
  vector<int> cnth(H, 0);
  vector<int> cntw(W, 0);
  set<pii> st;
  rep(i, m){
    int h, w;
    cin >> h >> w;
    h--, w--;
    cnth[h]++;
    cntw[w]++;
    st.insert(mp(h, w));
  }

  int mah = 0;
  int maw = 0;
  rep(i, H) chmax(mah, cnth[i]);
  rep(i, W) chmax(maw, cntw[i]);
  vector<int> ih;
  vector<int> iw;
  rep(i, H) if(cnth[i] == mah) ih.push_back(i);
  rep(i, W) if(cntw[i] == maw) iw.push_back(i);

  rep(i, ih.size()){
    rep(j, iw.size()){
      if(!st.count(mp(ih[i], iw[j]))){
        cout << mah + maw << endl;
        return 0;
      }
    }
  }

  cout << mah + maw -1 << endl;

  return 0;
}
