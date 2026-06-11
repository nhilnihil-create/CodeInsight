#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N;
ll M, a[100100];

ll lcm(ll a, ll b) {return a/__gcd(a,b)*b; }
int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N>>M;
  for(int i=0;i<N;i++) cin>>a[i];

  ll p=a[0] - (a[0] & (a[0]-1));

  ll m = a[0]>>1;
  for(int i=1;i<N;i++) {
    if ((a[i]&(p-1)) || !((a[i]/p)&1)){
      cout<<"0\n";
      return 0;
    }
    m = lcm(m, a[i]>>1);
  }

  // cout << p << ' ' << m << endl;
  cout << M/m - M/(2*m) << endl;

  return 0;
}
