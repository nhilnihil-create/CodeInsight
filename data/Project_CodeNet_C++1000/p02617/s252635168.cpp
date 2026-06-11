#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

LL f(LL n) {
  return (n * (n + 1)) / 2; 
}

int main() {
  int n;
  S(n);
  LL tot = 0;
  rep(i,1,n+1) {
    tot += f(i);
  }
  rep(i,0,n-1) {
    int u,v;
    S2(u,v);
    if(u > v) swap(u,v);
    tot -= u * 1LL * (n + 1 - v);
  }
  cout << tot << "\n";
  return 0;
}
