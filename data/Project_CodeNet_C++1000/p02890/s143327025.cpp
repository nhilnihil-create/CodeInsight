#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
typedef long long ll;
typedef long double ld;
using namespace std;
template<class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

const int N = 3e5 + 10;
int a[N];
int cnt[N];
int ans[N];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  multiset<int> z;
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) z.insert(cnt[i]);
  }

  for (int i = n; i >= 1; i--) {
    if (z.size() < i) {
      ans[i] = 0;
    } else {
      ans[i] = *z.begin();
    }
    if (z.size() == i && i > 1) {
      int v = *z.begin();
      z.erase(z.find(v));
      while (v--) {
        int u = *z.begin();
        z.erase(z.find(u));
        ++u;
        z.insert(u);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}