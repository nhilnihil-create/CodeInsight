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
  int K;
  cin >> K;
  set<ll> st;
  set<ll> st2;
  REP(i,9){
    st.insert(i+1);
    st2.insert(i+1);
  }
  REP(i,10){
    set<ll> st3;
    for(auto p:st2){
      ll x=p%10;
      ll y=p*10;
      st3.insert(x+y);
      if(x>0){
        st3.insert(x+y-1);
      }
      if(x<9){
        st3.insert(x+y+1);
      }
    }
    st2.erase(ALL(st2));
    for(auto s:st3){
      st2.insert(s);
    }
    for(auto r:st2){
      st.insert(r);
    }
  }

  int j=1;
  for(auto q:st){
    if(j==K){
      cout << q << endl;
      break;
    }
    j++;
  }
}