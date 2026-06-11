#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define bitrep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
using ll = long long;
using pii = pair<int, int>;
using si = set<int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 100'000'000;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

ll PowMod(ll modSeed, ll tgt, int powSeed){
  ll res = 1;
  rep(i,powSeed){
    res = (res*tgt) % modSeed;
  }
  return res;
}

string S;
ll N,cnt;

int main(){
  cin >>N;
  ll ans  = PowMod(modSeed,10,N) - PowMod(modSeed,9,N) - PowMod(modSeed,9,N) + PowMod(modSeed,8,N);
  ans %= modSeed;
  ans += modSeed;
  ans %= modSeed;
  printl(ans);
}
