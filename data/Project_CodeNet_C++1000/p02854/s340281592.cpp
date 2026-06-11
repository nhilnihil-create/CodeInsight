#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n; 
long long a[202020];

int main(){
  cin >> n;
  long long right = 0,  res = 1e18;
  rep(i, n){
    cin >> a[i];
    right += a[i];
  }
  long long left = 0;
  rep(i, n){
    //cerr << left << " " << right << " " << abs(right - left) << endl;
    chmin(res, abs(right - left));
    left += a[i];
    right-= a[i];
  }
  cout << res << endl;
}
