#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<ll> H(N + 1, 0);
  for (ll i = 1; i < N + 1; i++)
  {
    cin >> H.at(i);
  }

  // dp[i][j][k] := i 個目まで見た, j 回削除した, いちばん右が k 番目
  vector<vector<vector<ll>>> dp(N + 2, vector<vector<ll>>(K + 1, vector<ll>(N + 1, INF)));
  dp.at(0).at(0).at(0) = 0;
  for (ll i = 0; i < N + 1; i++)
  {
    for (ll j = 0; j <= K; j++)
    {
      for (ll k = 0; k < N; k++)
      {
        // 削除する
        if (j != K)
          chmin(dp.at(i + 1).at(j + 1).at(k), dp.at(i).at(j).at(k));

        // 削除しない
        chmin(dp.at(i + 1).at(j).at(i), dp.at(i).at(j).at(k) + max(0LL, H.at(i) - H.at(k)));
      }
    }
  }

  ll ans = *min_element(dp.at(N + 1).at(K).begin(), dp.at(N + 1).at(K).end());
  cout << ans << endl;
}