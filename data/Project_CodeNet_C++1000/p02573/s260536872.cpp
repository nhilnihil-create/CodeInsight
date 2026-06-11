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

int N, M;
vector <int> Graph[int(2e5+5)];
int Group[int(2e5+5)];
int cnt[int(2e5+5)];

int DFS(int num){
  Group[num] = num;
  queue <int> que; que.push(num);

  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int j : Graph[Q]){
      if (Group[j] != 0) continue;
      Group[j] = num;
      que.push(j);
    }
  }
  return 0;
}

int main(){
  cin >> N >> M;

  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }

  for (int i = 1; i <= N; i++){
    if (Group[i] != 0) continue;
    DFS(i);
  }

  for (int i = 1; i <= N; i++){
    cnt[Group[i]]++;
  }
  sort(cnt + 1, cnt + N + 1, greater<int>());
  cout << cnt[1] << endl;



  return 0;
}
