#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

int main(){
  string S;
  cin >> S;
  if(S=="SUN"){
    cout << 7 << endl;
  }else if(S=="MON"){
    cout << 6 << endl;
  }else if(S=="TUE"){
    cout << 5 << endl;
  }else if(S=="WED"){
    cout << 4 << endl;
  }else if(S=="THU"){
    cout << 3 << endl;
  }else if(S=="FRI"){
    cout << 2 << endl;
  }else{
    cout << 1 << endl;
  }
}