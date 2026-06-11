#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n;
  cin >> n;
  vvint A(n,vint(n-1));
  rep(i,0,n){
    rep(j,0,n-1){
      cin >> A[i][j];
      A[i][j]--;
    }
    reverse(A[i].begin(),A[i].end());
  }
  vector<P> match;
  auto judge = [&](int i){
    if(A[i].size() == 0) return;
    int j = A[i].back();
    if(A[j].size() == 0) return;
    if(A[j].back() == i){
      if(i < j) swap(i,j);
      match.push_back(P(i,j));
    }
  };
  rep(i,0,n){
    judge(i);
  }
  int day = 0;
  while(match.size() > 0){
    day++;
    sort(match.begin(),match.end());
    match.erase(unique(match.begin(),match.end()),match.end());
    vector<P> prevQ;
    swap(prevQ,match);
    for(P p:prevQ){
      int i = p.first;
      int j = p.second;
      A[i].pop_back();
      A[j].pop_back();
    }
    for(P p:prevQ){
      int i = p.first;
      int j = p.second;
      judge(i);
      judge(j);
    }
  }
  rep(i,0,n){
    if(A[i].size() != 0){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << day << endl;
}