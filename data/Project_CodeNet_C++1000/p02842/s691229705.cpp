#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;

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
ll N,D,ans;

int main(){
  ans = 0;
  cin >> N;
  for(int i=1;i<=N;i++){
    int pay = i * 1.08;
    if(pay==N){
      printl(i);
      return 0;
    }
  }
  printl(":(");
}
