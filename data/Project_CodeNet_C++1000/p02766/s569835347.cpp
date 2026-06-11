#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}
 
int main(){
  int n, k;
  cin >> n >> k;
  int ans = 0;
  while(n>0){
    n /= k;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
