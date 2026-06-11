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

struct bnum { ll i; ll n; };

auto bgr = [](bnum x, bnum y) { return x.n<y.n; };

int main() {
  int N; cin >> N;
  ll A[N]; rep(i,N) cin >> A[i];
  ll B[N]; rep(i,N) cin >> B[i];
  priority_queue<bnum,vector<bnum>,decltype(bgr)> pb(bgr);
  rep(i,N) pb.push({i,B[i]});

  ll result = 0;
  while (pb.size()) {
    bnum now = pb.top(); pb.pop();
    int l = (now.i-1+N)%N, r = (now.i+1)%N;
    int count = (now.n-A[now.i]) / (B[l]+B[r]);
    if (count) {
      B[now.i] -= count * (B[l]+B[r]);
      result += count;
      if (B[now.i]!=A[now.i]) pb.push({now.i,B[now.i]});
    }
    else if (B[now.i]!=A[now.i]) { result = -1; break; }
  }
  cout << result << endl;
  return 0;
}