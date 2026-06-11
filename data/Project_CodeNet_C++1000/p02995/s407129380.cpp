#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  long long int A = 0,B = 0,C = 0,D = 0;
  cin >> A >> B >> C >> D;
  long long int a = 0,b = 0,c = 0,g = 0,l = 0;
  long long int aa = 0,bb = 0,cc = 0,dd = 1;
  aa = C,bb = D;
  while(dd != 0){
    cc = aa/bb;
    dd = aa%bb;
    aa = bb;
    bb = dd;
  }
  l = aa;
  a = B/C;
  b = B/D;
  g = C*D/l;
  c = B/g;
  //cout << g << endl;
  //cout << a << b << c << endl;
  long long int answer = B - (a + b - c);
  a = (A - 1)/C;
  b = (A - 1)/D;
  //g = C*D/l;
  c = (A-1)/g;
  //cout << a << b << c << endl;
  answer = answer - (A - (a + b - c));

  cout <<  answer  + 1 << endl;
}

/*#include<bits/stdc++.h>
using namespace std ;
#define rep(i,N) for(int i = 0 ; i <(N) ; i++)
typedef long long ll;


ll f(ll x , ll C , ll D){
  ll res = x ;
  res -= x/C ;
  res -= x/D ;
  res += x/lcm(C,D) ;
  return res ;
}


int main(){
  ll A , B  ;
  ll C , D ;
  cin >> A >> B >> C >> D ;

  ll ans = f(B, C ,D) - f(A-1,C,D) ;
  cout << ans << endl ;
  return 0 ;

}*/
