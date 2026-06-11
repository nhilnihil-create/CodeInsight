#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
using ll = long long;

int n,m,a,b,c,d,k;
string s,t;

int main() {
  cin >> a >> b >> c >> d >> k;
  cout << c*60+d-(a*60+b)-k << endl;
}