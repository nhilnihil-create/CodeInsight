#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
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
  ll N;
  cin >> N;
  vector<pair<ll, ll>> Pi(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> Pi.at(i).first;
    Pi.at(i).second = i + 1;
  }
  sort(Pi.begin(), Pi.end(), greater<pair<ll, ll>>());

  ll ans = 0;
  multiset<ll> st = {0, 0, N + 1, N + 1};
  for (ll i = 0; i < N; i++)
  {
    ll p = Pi.at(i).first;
    ll c = Pi.at(i).second;
    st.emplace(c);
    auto it = st.lower_bound(c);
    it--;
    ll l1 = *it;
    it--;
    ll l0 = *it;
    it++, it++;
    it++;
    ll r0 = *it;
    it++;
    ll r1 = *it;

    ll tmp = p * ((l1 - l0) * (r0 - c) + (c - l1) * (r1 - r0));
    ans += tmp;
  }
  cout << ans << endl;
}