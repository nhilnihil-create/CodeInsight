#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;


vector<pair<double , double> > cor;

int factrial (int n) {
  if(n == 0) return 1;
  else return n*factrial(n-1);
}

int main() {
  int N;
  cin >> N;
  int ord[N];
  rep(i,N) {
    double x,y;
    cin >> x >> y;
    cor.push_back(make_pair(x,y));
    ord[i] = i;
  }
  double ans = 0;
  
  do{
    double sum = 0;
    rep(i,N-1) {
      double x = cor[ord[i]].first - cor[ord[i+1]].first;
      double y = cor[ord[i]].second - cor[ord[i+1]].second;
      sum += sqrt(x*x + y*y);
    }
    ans += sum;
    // cout << sum << endl;
  }while(next_permutation(ord,ord + N));

  ans /= factrial(N);
  printf("%.10lf\n", ans);

  return 0;
}








