#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

ll calculateMod(ll n, ll expo, ll modSeed){
  ll ret = 1;
  rep(i, expo){
    ret *= n;
    ret = ret%modSeed;
  }
  return ret;
}

int main(){
    ll N;
    cin >> N;
    ll ans = calculateMod(10,N, modseed);
    ans -= calculateMod(9, N, modseed)*2;
    ans += calculateMod(8,N,modseed);
    ans %= modseed;
    ans=(ans+modseed)%modseed;
    printl(ans);
}
