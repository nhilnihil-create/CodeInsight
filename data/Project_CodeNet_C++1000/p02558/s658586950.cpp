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

struct UnionFind{
  int N, Group[int(2e5+5)];
  void Make(){
    for (int i = 1; i <= N; i++) Group[i] = i;
  }
  void Union(int u, int v){
    int Gu = Group[u], Gv = Group[v];
    while (Gu != Group[Gu]) Gu = Group[Gu];
    while (Gv != Group[Gv]) Gv = Group[Gv];
    Group[u] = min(Gu, Gv);
    Group[v] = min(Gu, Gv);
    Group[max(Gu, Gv)] = min(Gu, Gv);
  }
  bool Check(int u, int v){
    int Gu = Group[u], Gv = Group[v];
    while (Gu != Group[Gu]) Gu = Group[Gu];
    while (Gv != Group[Gv]) Gv = Group[Gv];
    if (Gu == Gv) return true;
    else return false;
  }
};

int main(){
  int N, Q; cin >> N >> Q;
  UnionFind UF; UF.N = N; UF.Make();

  for (int i = 0; i < Q; i++){
    int T, U, V; cin >> T >> U >> V;
    if (T == 0) UF.Union(U, V);
    else cout << UF.Check(U, V) << endl;
  }

  return 0;
}
