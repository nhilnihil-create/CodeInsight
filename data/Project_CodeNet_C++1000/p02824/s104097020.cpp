// Oh boi here we go again
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pi pair < int, int >
#define pii pair < int, pi >
#define next next123
#define left left123

const int N = 1e5 + 7;
const int INF = 1e9 + 7;

int a[N];
int n, m, v, p;

bool solve (int k){
    ll s = 0;
    if (a[p] > a[k] + m)
        return false;
    for (int i = p; i < k; i++)
        s += min(m, (a[k] + m) - a[i]);
    int r = v - p - n + k;
    if (s / m >= r)
        return true;
    return false;
}

main(){
    cin >> n >> m >> v >> p;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    int l = p, r = n + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        if (solve(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
}
