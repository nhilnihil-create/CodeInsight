#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll f(ll num)
{
    if (num < 2) return 1;
    else if (num == 2) return 2;
    else if (num % 2 == 0) return 2; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return i;
        }
    }

    // 素数である
    return num;
}

vector<ll> factorList(ll x) {
  vector<ll> res;
  while (x != 1) {
    res.push_back(f(x));
    x /= f(x);
  }
  return res;
}

int main(){
  ll a, b;
  cin >> a >> b;
  vector<ll> af=factorList(a);
  vector<ll> bf=factorList(b);
  map<ll, int> ma;
  ll ans=1;
  for(ll p: af){
    ma[p]++;
  }
  for(ll p: bf){
    if(ma[p]>0){
      ma[p]=0;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
