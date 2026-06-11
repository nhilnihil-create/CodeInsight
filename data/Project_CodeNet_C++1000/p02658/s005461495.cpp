#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll maxN = 1'000'000'000'000'000'000;


template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

ll culSum(vector<ll> inputs){
  ll ret = 1;
  rep(i,inputs.size()){
    if(inputs.at(i)==0){
      return 0;
    }
  }
  rep(i,inputs.size()){
    if(inputs.at(i) <= maxN/ret){
        ret *= inputs.at(i);
    }else{
      return -1;
    }
  }
  return ret;
}

int main(){
    int N;
    cin >> N;
    auto inputs = getValues<ll>(N);
    printl(culSum(inputs));
}
