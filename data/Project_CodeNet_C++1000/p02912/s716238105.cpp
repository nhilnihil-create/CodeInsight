#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 123;
#define int long long 
int n, m;
pair <int, int> a[maxn];
string s[60], t[60];
main () { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    multiset<int> q;
    for(int i = 1; i <= n; i++) {
    	int x;
    	cin >> x;
    	q.insert(x);
    }

    for(int i = 1; i <= m; i++) {
    	int x = *q.rbegin();
    	q.erase(q.find(x));
    	x /= 2;
    	q.insert(x);
    }

    int ans = 0;
    while(q.size()) {
    	int x = *q.begin();
    	ans += x;
    	q.erase(q.find(x));
    }
    cout << ans;
}


