#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  
  map<P,int> mp;
  REP(i,N){
    REP(j,N){
      if(i!=j){
        mp[make_pair(A[i].first-A[j].first,A[i].second-A[j].second)]++;
      }
    }
  }

  int MAX=0;
  for(auto x:mp){
    int cnt=0;
    REP(i,N){
      REP(j,N){
        if(i!=j){
          if(A[i].first-A[j].first==x.first.first&&A[i].second-A[j].second==x.first.second){
            cnt++;
          }
        }
      }
    }
    MAX=max(MAX,cnt);
  }

  cout << N-MAX << endl;
}