#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int h, w, m; cin >> h >> w >> m;
  vector<int> H(h);
  rep(i, h)H[i] = 0;
  vector<int> W(w);
  rep(i, w)W[i] = 0;
  set <P> grid;
  rep(i, m){
    int a, b; cin >> a >> b;
    a--;
    b--;
    H[a]++;
    W[b]++;
    grid.emplace(a, b);
  }
  
  int h_max = *max_element(H.begin(), H.end());
  int w_max = *max_element(W.begin(), W.end());
  vector<int> h_sec;
  vector<int> w_sec;
  rep(i, h){
    if (H[i] == h_max){
      h_sec.push_back(i);
    }
  }
  rep(i, w){
    if (W[i] == w_max){
      w_sec.push_back(i);
    }
  }
  int ans = h_max + w_max;
  int sub = 1;
  for (int i:h_sec){
    for (int j:w_sec){
      if (!grid.count(P(i, j))){
        sub = 0;
        break;
      }
    }
    if (sub == 0)break;
  }
  cout << ans-sub <<endl;
} 