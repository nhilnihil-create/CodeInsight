#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  ll Q;
  cin >> S >> Q;
  deque<ll> ST;
  for(char c : S){
    ST.push_back(c);
  }
  ll count=0;
  for(ll i=0;i<Q;i++){
    ll T;
    cin >> T;
    if(T==1){
      count++;
    }
    else if(T==2){
      ll F;
      char C;
      cin >> F >> C;
      if((F==1 && count%2==0) || (F==2 && count%2==1)){
        ST.push_front(C);
      }
      else if((F==1 && count%2==1) || F==2 && count%2==0){
        ST.push_back(C);
      }
    }
  }
    if(count%2==1){
      reverse(ST.begin(),ST.end());
    }
  for(char x : ST){
    cout << x;
  }
}