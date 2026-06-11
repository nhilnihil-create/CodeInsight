#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  ll a, b, k;
  cin >> a >> b >> k;
  ll ansa = max(0LL, a-k);
  ll ansb = min(b, b-(k-a));
  ansb = max(ansb, 0LL);
  cout << ansa << " " << ansb << endl;
  return 0;
}
