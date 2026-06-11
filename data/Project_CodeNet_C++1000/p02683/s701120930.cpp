#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;
using piv = pair<ll,vector<ll>>;

const ll modSeed = pow(10,9) + 7;
const int INF = 1'000'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll N,M,X,ans;

int main(){
  ans = -1;
  cin >> N>>M>>X;
  vector<piv> books(N);
  rep(i,N){
    ll C;
    cin >>C;
    books[i] = make_pair(C, getVector<ll>(M));
  }

  for(int i=0;i<(1<<N);i++){
    vector<ll> skill(M,0LL);
    ll price =0;
    for(int j=0;j<N;j++){
      if(i&(1<<j)){
        price+=books[j].first;
        for(int h=0;h<M;h++){
          skill[h]+=books[j].second[h];
        }
      }
      bool flg = true;
      for(int j=0;j<M;j++){
        if(skill[j]<X){
          flg = false;
          break;
        }
      }
      if(flg){
        if(ans==-1){
          ans = price;
        }else{
          ans = min(ans,price);
        }
      }
    }
  }

  printl(ans);
}
