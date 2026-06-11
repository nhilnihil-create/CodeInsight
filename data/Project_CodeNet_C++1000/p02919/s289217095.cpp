#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

struct ST {
  int p;
  int i;
};
bool operator<(const ST& x, const ST& y){
  return x.i < y.i;
}

int main(){
  int N;
  cin >> N;
  vector<ST> v;
  rep(i,N){
    ST st;
    cin >> st.p;
    st.i = i;
    v.push_back(st);
  }
  sort(ALLOF(v),[](const ST& x, const ST& y){ return x.p > y.p; });

  ll ret = 0;
  set<ST> s;
  rep(i,N){
    ST st = v[i];
    s.insert(st);

    int rhs2 = N;
    int rhs1 = N;
    int pos = st.i;
    int lhs1 = -1;
    int lhs2 = -1;

    auto itr = s.find(st);
    itr++;
    if(itr != s.end()){
      rhs1 = itr->i;

      itr++;
      if(itr != s.end()){
        rhs2 = itr->i;
      }
    }
    auto itl = s.find(st);
    if(itl != s.begin()){
      itl--;
      lhs1 = itl->i;
      
      if(itl != s.begin()){
        itl--;
        lhs2 = itl->i;
      }
    }

    //cout << lhs2 << " " << lhs1 << " " << pos << " " << rhs1 << " " << rhs2 << endl;

    ll a = pos - lhs1;
    ll b = lhs1 - lhs2;
    ll c = rhs1 - pos;
    ll d = rhs2 - rhs1;

    //cout << a << " " << b << " " << c << " " << d << endl;
    ret += st.p * (b*c + a*d);
  }
  
  cout << ret << endl;
  
  return 0;
}

