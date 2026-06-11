#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, n-1) if(s[i] == s[i+1]) cnt++;
  cout << min(cnt + 2 * k, n - 1) <<endl;
}