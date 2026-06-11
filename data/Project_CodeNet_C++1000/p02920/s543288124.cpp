#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes(){
  cout << "Yes" << endl;
  exit(0);
}

void no(){
  cout << "No" << endl;
  exit(0);
}

int main(){
  ll N; cin >> N;
  ll T = 1<<N;
  vector<ll> S(T);
  REP(i,T) cin >> S[i];
  sort(ALL(S));
  multiset<ll> generated, unfinished;
  generated.insert(-S[T-1]);
  REP(i,T-1) unfinished.insert(-S[i]);
  REP(i,N){
    //generatedへ移す用
    vector<ll> tmp;
    auto it = generated.begin();
    while(it!=generated.end()){
      auto ub = unfinished.upper_bound((*it));
      if(ub==unfinished.end()) no();
      tmp.push_back(*ub);
      unfinished.erase(ub);
      it++;
    }
    FOREACH(x,tmp) generated.insert(x);
  }
  yes();
}

