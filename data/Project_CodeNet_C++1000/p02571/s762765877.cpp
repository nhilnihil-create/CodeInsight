#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> P;

struct edge {int to, cost; };

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
  string s, t;
  cin >> s >> t;
  int ans = 0;
  int n=s.length(), m=t.length();
  for(int i=0; i<n-m+1; i++){
    int tmp = 0;
    for(int j=0; j<m; j++){
      if(s[i+j]==t[j]) tmp++;
    }
    ans = max(ans, tmp);
  }
  ans = m-ans;
  cout << ans << endl;
  return 0;
}
