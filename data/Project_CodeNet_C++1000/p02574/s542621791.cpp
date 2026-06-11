#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll cnt[1000006];

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll allgcd = a[0];
  rep(i,n)allgcd = __gcd(allgcd,a[i]);
  if(allgcd > 1){
    cout << "not coprime" << endl;
  }else{
    // 与えられた数をそれぞれ素因数分解していく
    rep(i,n){
      ll now = a[i];
      for(ll j=2;j*j<=now;j++){
        if(now%j==0){
          while(now%j==0)now/=j;
          cnt[j]++;
        }
      }
      if(now>1)cnt[now]++;
    }
    for(int i=2;i<=1e6;i++){
      if(cnt[i]>1){
        cout << "setwise coprime" << endl;
        return 0;
      }
    }
    cout << "pairwise coprime" << endl;
  }
}