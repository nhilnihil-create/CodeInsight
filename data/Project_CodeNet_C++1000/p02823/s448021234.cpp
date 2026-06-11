#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
  ll N;
  cin >> N;
  ll A,B;
  cin >> A >> B;
  ll cnt=0;
  if(abs(A-B)%2==0){
    cnt = abs(A-B)/2;
  }
  else{
    ll a_lengh,b_lengh;
    a_lengh = min(abs(N-A),abs(A-1));
    b_lengh = min(abs(N-B),abs(B-1));
    ll lengh = min(a_lengh,b_lengh);
    cnt = (abs(A-B)+1)/2 + lengh;
  }
  cout << cnt << endl;
}