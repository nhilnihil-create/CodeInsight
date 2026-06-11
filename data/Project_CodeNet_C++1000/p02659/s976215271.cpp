#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  ll a;
  string s;
  cin >> a >> s;
  int k = 0;
  k += s[0]-'0';
  k = k*10+s[2]-'0';
  k = k*10+s[3]-'0';
  a*=k;
  cout << a/100 << endl;
}
