#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define li long int

#define pb push_back
#define m <i> map<int>
#define v <i> vector<int>

const int MX = 1e6;
const int MOD = 1e9 + 7;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const double PI = 3.1415926535;

#define rep(i, n) for(int i=0; i<n; i++)

int main()
{
  IOS;
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans=(ll)n/(a+b)*a;
  ll r=n%(a+b);
  ans+=min(r,a);
  cout << ans << endl;
  
  return 0;
}
