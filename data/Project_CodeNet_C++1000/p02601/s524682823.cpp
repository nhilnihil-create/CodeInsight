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
ll A,B,C,K,ans;

int main(){
  ans = 0;
  cin >> A>>B>>C>>K;
  for(int a=0;a<=K;a++){
    for(int b=0;b<=K-a;b++){
      for(int c=0;c<=K-a-b;c++){
        int rA = A*pow(2,a);
        int rB = B*pow(2,b);
        int rC = C*pow(2,c);
        if((rB>rA)&&(rC>rB)){
          printl("Yes");
          return 0;
        }
      }
    }
  }
  printl("No");
}
