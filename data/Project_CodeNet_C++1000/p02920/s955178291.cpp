#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int num = pow(2,N);
  map<int,int,greater<int>> slime; 
  rep(i,num) { int tmp; cin >> tmp; slime[tmp]++; }

  int now[num]; now[0] = (*slime.begin()).first;
  if (slime[now[0]]==1) slime.erase(now[0]);
  else slime[now[0]]--;
  int p = 1;
  rep(i,N) {
    rep(j,pow(2,i)) {
      auto pos = slime.upper_bound(now[j]);
      if (pos==slime.end()) { 
        cout <<  "No" << endl;
        return 0;
      }
      now[p+j] = (*pos).first;
      if ((*pos).second==1) slime.erase((*pos).first);
      else (*pos).second--;
    }
    p += pow(2,i);
  }

  cout << "Yes" << endl;
  return 0;
}