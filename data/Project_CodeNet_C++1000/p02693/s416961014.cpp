#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll k;
    cin >> k;
  ll a, b;
  cin >> a >> b;
  for (ll i = a; i <= b; i++) {
    if(i % k == 0) {
        cout << "OK" << endl;
        return 0;
    }
  }

  cout << "NG" << endl;
   return 0;
}

