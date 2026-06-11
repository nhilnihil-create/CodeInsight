#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int n;
vector<int> edge[100000];
map<P, int> mp;
queue<P> q;
int cnt = 0;

void dfs(int current, int last, int color){
  for(int x : edge[current]){
    if(x == last) continue;
    color = (color+1) % cnt;
    if(mp.count(P(current, x))) mp[P(current, x)] = color;
    else mp[P(x, current)] = color;
    dfs(x, current, color);
  }
}

int main(){
  cin >> n;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
    mp[P(a, b)] = -1;
    q.push(P(a, b));
  }
  
  rep(i, n) cnt = max(cnt, int(edge[i].size()));
  
  dfs(0, -1, -1);
  cout << cnt << endl;
  rep(i, n-1){
    cout << mp[q.front()]+1 <<endl;
    q.pop();
  }
}

