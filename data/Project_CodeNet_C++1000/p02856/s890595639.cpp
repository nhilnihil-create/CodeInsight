#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll m,cnt=0,sum=0,d,c;
  cin >> m;
  for(int i=0; i<m; i++) {
    cin >> d >> c;
    sum+=d*c;
    cnt+=c;
  }
  cout << (sum-1)/9+cnt-1 << endl;
}