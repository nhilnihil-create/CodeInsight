#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define rep(i,N) for(ll i=0;i<ll(N);++i)
int main() {
  ll N,K;
  cin >> N >> K;
  vector<ll> tele(N);
  rep(i,N){
    cin >> tele.at(i);
    tele.at(i) --;
    //cout << tele.at(i)<< " ";
  }
  //cout << endl;
  ll loop = 0,now = 1 - 1;
  vector<ll> memo(N,0);
  memo.at(now) = 0;
  //町は1-indexに注意
  ll point;
  bool fin = true;
  rep(i,K){
    now = tele.at(now);
    //cout << "now = " << now << endl;
    if(memo.at(now) == 0){
      memo.at(now) = i+1;
      //cout << "memo = " << memo.at(now) << endl;
      continue;
    }
    if(memo.at(now) != 0){
      loop = i + 1 - memo.at(now);
      point = i + 1;
      fin = false;
      //cout << "break" << endl;
      break;
    }
  }
  if(fin){
    cout << now + 1 << endl;
    return 0;
  }
  ll rest = (K - point) % loop;
  //cout <<"rest = " <<  rest << endl;
  rep(i,rest){
    now = tele.at(now);
  }
  cout << now + 1 << endl;
  return 0;
}