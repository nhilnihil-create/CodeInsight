//g++ -std=gnu++14 a.cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

int main() {
  ll N,M;
  cin >> N >> M;
  int a = N;
  int b = 1+M;
  int flag = 1;
  for(int i = 1;i <= M;i++){
    if(flag%2==1){
      cout << b << " " << b+i << endl;
      b--;
      flag--;
     }else{
       cout << a << " " << a-(N-i) << endl;
       a--;
       flag++;
    }
  }
}
