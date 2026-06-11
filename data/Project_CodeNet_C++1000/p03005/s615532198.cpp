#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,h,w;
string s,t;

int main() {
  cin >> n >> k;
  cout << (k==1 ? 0 : n-k) << endl;
}