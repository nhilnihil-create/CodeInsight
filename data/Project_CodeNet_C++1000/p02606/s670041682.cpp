#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

const int MAX=1e6+5;

int main() {
  int L,R,d;
  cin>>L>>R>>d;
  cout<<R/d-(L-1)/d<<endl;
  return 0;  
}