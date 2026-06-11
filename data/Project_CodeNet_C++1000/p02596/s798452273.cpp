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
    ll K;
    cin >> K;
    vector<ll> mods(K+1);
    mods.at(1) = 7%K;
    for(int i=2;i<=K;i++){
      mods.at(i) = (mods.at(i-1) * 10 + 7)%K;
    }
    for(int i=1;i<=K;i++){
      if(mods.at(i)==0){
        printl(i);
        return 0;
      }
    }
    printl(-1);
}
