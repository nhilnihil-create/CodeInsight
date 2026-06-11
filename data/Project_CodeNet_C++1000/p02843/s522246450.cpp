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
ll X,ans;

int main(){
  ans = 0;
  cin >> X;
  int dig = X % 100;
  int x =0;
  int rem = dig%5;
  x+= dig/5;
  if(rem!=0){
    x++;
  }
  int m = 100*x+dig;
  if(X<m){
    printl(0);
    return 0;
  }
  printl(1);
}
