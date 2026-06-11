#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n) for(auto i=s, i##_len=(n); i<i##_len; ++i)

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(a)  (a).begin(),(a).end()

struct Tree {
  vector<int> next;
  ll count=0;
  ll ans=0;
  bool reach = false;
};

int N,Q;
vector<Tree> tr;

void DFS(int n, ll preva) {
  if (tr[n].reach == true) return;

  tr[n].reach = true;
  tr[n].ans = tr[n].count + preva;
  for (auto i : tr[n].next) {
    DFS(i,tr[n].ans);
  }
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N  >> Q;


  tr.resize(N+1);

  REP(i,N-1) {
    int a,b;
    cin >> a >> b;
    tr[a].next.PB(b);
    tr[b].next.PB(a);
  }

  REP(i,Q) {
    int a,b;
    cin >> a >> b;
    tr[a].count += b;
  }


  DFS(1,0);

  REP(i,N) {
    if (i == 0) cout << tr[1].ans ;
    else cout << " " << tr[i+1].ans;
  }
  cout << endl;

}
