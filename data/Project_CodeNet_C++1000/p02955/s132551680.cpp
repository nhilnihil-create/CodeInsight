#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N, K;
  cin >> N >> K;
  vector<lint> A(N);
  lint Asum = 0;
  REP(i, N) {
    cin >> A[i];
    Asum += A[i];
  }
  vector<lint> div;
  for(lint i=1; i*i<=Asum; i++) {
    if(Asum%i == 0) {
      div.push_back(i);
      if(i != Asum/i) div.push_back(Asum/i);
    }
  }
  sort(ALL(div));
  IREP(i, div.size()) {
    vector<lint> Amod(N);
    lint Amodsum = 0;
    REP(j, N) {
      Amod[j] = A[j]%div[i];
      Amodsum += Amod[j];
    }
    if(Amodsum%div[i] != 0) continue;
    lint x = Amodsum / div[i];
    sort(ALL(Amod), greater<lint>());
    lint sum = 0;
    REP(i, x) sum += Amod[i];
    if(x*div[i] - sum <= K) {
      cout << div[i] << endl;
      return 0;
    }
  }

}