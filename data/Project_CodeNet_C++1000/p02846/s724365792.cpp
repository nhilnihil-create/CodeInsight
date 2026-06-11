#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  long t1,t2;
  cin >> t1 >> t2;
  long a1,a2,b1,b2;
  cin >> a1 >> a2 >> b1 >> b2;
  long c1 = a1 - b1;
  long c2 = a2 - b2;
  if(c1 > 0 && c2 > 0){
    cout << 0 << endl;
    return 0;
  }
  if(c1 < 0 && c2 < 0){
    cout << 0 << endl;
    return 0;
  }
  if(abs(c1)*t1 > abs(c2)*t2){
    cout << 0 << endl;
    return 0;
  }
  if(abs(c1)*t1 == abs(c2)*t2){
    cout << "infinity" << endl;
    return 0;
  }
  long tmp = abs(c1)*t1;
  long d = abs(c2)*t2 - abs(c1)*t1;
  cout << (tmp / d) + (tmp + d - 1)/d << endl;
}
