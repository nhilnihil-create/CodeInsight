#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646;
const double pi = 3.141592653589793;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string s[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

  string s2;

  cin >> s2;

  for(int i = 0 ; i < 7 ; i++) {
    if(s2 == s[i]) {
      cout << 7 - i << endl;
    }
  }
} 