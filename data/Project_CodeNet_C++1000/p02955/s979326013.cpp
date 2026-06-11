#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;

int n, k, a[maxn];
int tot, ans;


bool can(int x) {
  int cost = 0;
  vector<int> v(n);
  for (int i=0; i<n; i++) {
    v[i] = a[i]%x;
  }
  sort(v.begin(), v.end());
  int l = 0;
  int r = n-1;
  while (l < r) {
    int dx = min(v[l], x-v[r]);
    cost += dx;
    v[l]-=dx; v[l]%=x;
    v[r]+=dx; v[r]%=x;
    if (v[l]==0) l++;
    if (v[r]==0) r--;
  }

  //cout<<x<<": "<<cost<<endl;
  return cost <= k;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n>>k;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    tot += a[i];
  }

  for (int f=1; f*f<=tot; f++) {
    if (tot%f==0) {
      if (can(f)) {
	ans = max(ans, f);
      }
      if (tot/f!=f && can(tot/f)) {
	ans = max(ans, tot/f);
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
