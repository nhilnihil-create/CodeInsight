#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll s = 0, sev = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(i%2) sev += a[i];
    s += a[i];
  }
  vector<ll> ans;
  ans.push_back(s-sev*2);
  for(int i=0; i<n; i++){
    if(i==n-1) ans.push_back(a[i]*2-ans[0]);
    else ans.push_back(a[i]*2-ans[i]);
    cout << ans[i] << " ";
  }
  return 0;
}
