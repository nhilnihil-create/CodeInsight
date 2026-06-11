//bayemirov
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

#define pb push_back

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
   int k;
   cin >> k;
   string res = "";
   while (k--)
   	res += "ACL";
   cout << res;
   return 0;
}