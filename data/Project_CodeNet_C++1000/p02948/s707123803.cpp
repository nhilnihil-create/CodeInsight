#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{
  int N, M; cin >> N >> M;
  vector<pair<int, int>> arr(N);
  rep(i, 0, N) cin >> arr[i].first >> arr[i].second;
  vector<vector<int>> works(100001);
  rep(i, 0, N){
    works[arr[i].first].push_back(arr[i].second);
  }

  priority_queue<int> pq;
  ll ans = 0;
  repe(i, 1, M){

    for(auto x: works[i]){
      pq.push(x);
    }

    if(!pq.empty()){
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
}
