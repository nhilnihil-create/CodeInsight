#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define Clear(arr) memset(arr,0,sizeof arr)
#define oo 1000000000
#define inf 1000000000000000000
#define M 998244353
using namespace std;
typedef long long ll;
const int N = 1e6+300;
const int SQRTN = 320;
const int LOGN = 20;
const double PI = acos(-1);
const double TAU = 2*PI;

int x;

void solve(){
  cin >> x;
  int k = 1;
  for(int i = 1;i<=360 ; i++){
    if((x*i)%360==0){
      k=i;
      break;
    }
  }
  cout << k << endl;

}


signed main() {
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
