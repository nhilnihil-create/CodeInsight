#include <iostream>
#include <vector>
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
#define REPS(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)


int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  set<string> s;
  set<string> s2;
  set<string> s3;
  int N;
  string _s;
  cin >>N;
  cin >> _s;

  REP(i,N-2) {
    string _s3 = _s.substr(i,1);
    if (s3.count(_s3) != 0) continue;
    s3.insert(_s3);

    REPS(j,i+1,N-1) {
      string _s2 = _s.substr(i,1) + _s.substr(j,1);
      if (s2.count(_s2) != 0) continue;

      s2.insert(_s2);
      REPS(k,j+1,N) {
        s.insert(_s2 + _s.substr(k,1));
      }
    }
  }


  cout << s.size() << endl;

}
