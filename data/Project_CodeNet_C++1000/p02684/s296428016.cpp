#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  ll n,k; cin >> n >> k;
  vi a(n); rep(i,n){ cin >> a[i]; a[i]--; }
  set<int> st;
  vi trace;
  int now = 0;
  rep(i,n){
    if(st.count(now)) break;
    st.insert(now);
    trace.push_back(now);
    now = a[now];
  }
  int i = 0;
  for(; trace[i] != now; i++){
    if(k == 0){
      cout << trace[i]+1;
      return 0;
    }
    k--;
  }
  int cnt = (int)trace.size()-i;
  cout << trace[i+k%cnt]+1;
  cout << "\n";
  return 0;
}
