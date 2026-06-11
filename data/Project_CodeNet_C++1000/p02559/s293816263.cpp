#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

struct SegmentTree{
  vector <ll> Tree[21];
  void Make(){
    for (int i = 0; i < 21; i++) Tree[i].resize(1<<i);
  }
  void Add(int loc, ll val){
    for (int i = 20; i >= 0; i--){
      Tree[i][loc] += val;
      loc /= 2;
    }
  }

  ll Sum(int loc){
    if (loc < 0) return 0;
    ll ans = Tree[20][loc];
    int now = 20;
    while (loc > 0){
      if (loc % 2 == 0){
        loc /= 2; loc--; now--;
      }else{
        loc--;
      }
      ans += Tree[now][loc];
    }
    return ans;
  }
};

int main(){
  SegmentTree T; T.Make();
  int N, Q; cin >> N >> Q;
  for (int i = 0; i < N; i++){
    ll A; cin >> A;
    T.Add(i, A);
  }

  for (int i = 0; i < Q; i++){
    ll A, B, C; cin >> A >> B >> C;
    if (A == 0){
      T.Add(B, C);
    }else{
      cout << T.Sum(C-1) - T.Sum(B-1) << endl;
    }
  }

  return 0;
}
