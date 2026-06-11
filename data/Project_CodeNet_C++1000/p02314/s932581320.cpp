#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
  int i,j,k,l;
  int n,m;
  int valid[50005] = {1,0,};
  int kazu[50005] = {0};
  cin >> n >> m;
  rep(i,m) {
    int c;
    cin >> c;
    rep(j,50000) {
      if(j+c > 50000) break;
      if(valid[j]) {
        if(valid[j+c] == 0 
          || kazu[j+c] > kazu[j]+1) {
          valid[j+c] = 1;
          kazu[j+c] = kazu[j]+1;
        }
      }
    }
  }
  cout << kazu[n] << endl;
  return 0;
}