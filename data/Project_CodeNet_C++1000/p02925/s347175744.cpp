#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

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

int N, A[1005][1005];
vector <int> Graph[int(1e6+5)];
int num[int(1e6+5)], day[int(1e6+5)];
bool visited[int(1e6+5)];

int Make(int i, int j){
  if (i < j) return N * i + j;
  else return N * j + i;
}

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++){
    for (int j = 0; j < N - 1; j++){
      cin >> A[i][j];
    }
    for (int j = 1; j < N - 1; j++){
      int before = Make(i, A[i][j-1]);
      int next = Make(i, A[i][j]);
      Graph[before].push_back(next);
      num[next]++;
    }
  }

  queue <int> que;
  for (int i = 1; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      int now = Make(i, j);
      if (num[now] == 0){
        que.push(now);
        visited[now] = true;
        day[now] = 1;
      }
    }
  }

  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int next:Graph[Q]){
      num[next]--;
      if (num[next] == 0){
        que.push(next);
        visited[next] = true;
        day[next] = day[Q] + 1;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      int now = Make(i, j);
      if (!visited[now]){
        cout << -1 << endl;
        return 0;
      }
      ans = max(ans, day[now]);
    }
  }
  cout << ans << endl;


  return 0;
}
