#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
 ll n;
 cin >> n;
 ll ans;
 for(ll i = 1; i <= sqrt(n); i++){
   ll a = i;
   if(n%a != 0)continue;
   ll b = n/a;
   ans = a+b-2;
 }
 cout << ans << endl;
}