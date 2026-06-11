#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n, m, q;
  cin >> n >> m >> q;
  cout << min((q+n-1)/n, (q+m-1)/m);
  return 0;
}