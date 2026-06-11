#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}



int main()
{
  INT(N);
  INT(K);
  if(K>(N-1)*(N-2)/2){
    cout << -1 << endl;
  }else{
    cout << (N-1)*(N-2)/2-K+(N-1) << endl;
    REP2(i,2,N){
      cout << 1 << " " << i << endl;
    }
    int cnt = 0;
    REP2(i,2,N-1){
      REP2(j,i+1,N){
        if(cnt==(N-1)*(N-2)/2-K){
          return 0;
        }
        cout << i << " " << j << endl;
        cnt++;
      }
    }
  }
}