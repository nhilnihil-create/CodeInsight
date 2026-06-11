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
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i=0; i<n; i++){
    cin >> x[i];
  }
  int ans = 1000000009;
  for(int i=1; i<=100; i++){
    int tmp = 0;
    for(int j=0; j<n; j++){
      tmp += (i-x[j])*(i-x[j]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
