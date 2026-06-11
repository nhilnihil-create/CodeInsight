#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, M;
  cin >> N >> M;

  ll p;
  string S;
  vl prob(N, 0);
  vl wa_cnt(N, 0);
  rep(i, M){
    cin >> p >> S;

    if(prob[p - 1] == 0){
      if(S == "WA"){
	wa_cnt[p - 1]++;
      } else{
	prob[p - 1] = 1;
      }
    }
  }

  ll ac = accumulate(prob.begin(), prob.end(), 0);
  ll wa = 0;
  rep(i, N) wa += prob[i] == 1 ? wa_cnt[i] : 0;

  cout << ac << ' ' << wa << "\n";
  
  return 0;
}
