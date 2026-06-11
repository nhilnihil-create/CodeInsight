#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(a,b) for(int i=a;i<b;i++)
#define nl "\n"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll d, t, s;
  cin >> d >> t >> s;
  if (t * s >= d)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}

