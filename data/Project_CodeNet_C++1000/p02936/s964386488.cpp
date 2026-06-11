#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
//bitset<64>(x).count()
//fixed << setprecision(15) << 

int main (){
  int n, q, x, y;
  cin >> n >> q;
  bool check[n+1] = {false};
  vector<int> cost(n+1);
  vector<vector<int>> a(n+1,vector<int>(0));
  rep(i,n-1){
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  rep(i,n+1){
    cost[i] = 0;
  }
  rep(i, q){
    cin >> x >> y;
    cost[x] += y;
  }
  queue<int> que;
  que.push(1);
  check[1] = true;
  while(que.size()!=0){
    int tmp = que.front();
    if(check[tmp]==true){
      que.pop();
      rep(i, (a[tmp]).size()){
        if(!check[a[tmp][i]]){
          cost[a[tmp][i]] += cost[tmp];
          check[a[tmp][i]] = true;
          que.push(a[tmp][i]);
        }
      }
    } else {
      que.pop();
      que.push(tmp);
    }
  }
  for(int i=1;i<=n;i++)
    cout << cost[i] << " " ;
  cout << endl;
}
