#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  string s;
  cin >> s;
  if(s=="RRR") cout << 3 << endl;
  else if(s=="RRS"||s=="SRR") cout << 2 << endl;
  else if(s=="SSS") cout << 0 << endl;
  else cout << 1 << endl;
}