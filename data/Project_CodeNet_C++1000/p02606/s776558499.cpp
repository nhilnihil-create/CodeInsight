#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define wzh(x) cerr<<#x<<' '<<x<<endl
int l,r,d;
int main() {
  ios::sync_with_stdio(false);
  cin>>l>>r>>d;
  cout<<(r/d)-(l-1)/d<<'\n';
 	return 0;
}