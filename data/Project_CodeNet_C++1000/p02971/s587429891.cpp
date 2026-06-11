#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[200010];
multiset<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i=0;i<n;i++) {
        s.erase(s.find(a[i]));
        cout << *s.rbegin() << endl;
        s.insert(a[i]);
    }
}
