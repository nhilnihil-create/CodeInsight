#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll X;
    cin >> X;
    ll out = 100;
    for (int i = 1;; i++){
      out += out /100;
      if(out>=X){
          cout << i << endl;
          break;
      }
    }
    return 0;
}