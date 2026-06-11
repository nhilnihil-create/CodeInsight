#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  int n, k, c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  vi vn(n);
  vi vr(n);
  int i = 0;
  int cntn = 0;
  while(i<n && cntn<k) {
    if(s[i]=='o') {
      cntn++;
      vn[i] = cntn;
      i += (c+1);
    }
    else i++;
  }
  int j = n-1;
  int cntr = 0;
  while(j>=0 && cntr<k) {
    if(s[j]=='o') {
      cntr++;
      vr[j] = cntr;
      j -= (c+1);
    }
    else j--;
  }
  // rep(i,n) cout << vn[i];
  // cout << endl;
  // rep(i,n) cout << vr[i];
  // cout << endl;
  rep(i,n) if(vn[i]!=0 && vn[i]+vr[i]==k+1) cout << i+1 << endl;
  return 0;
}