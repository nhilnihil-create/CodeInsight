#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main() {
    fastio;
    int a, b, m;
    cin >> a >> b >> m;

    int* fri = new int[a];
    int* mic = new int[b];

    for (int i = 0; i < a; ++i) cin >> fri[i];
    for (int i = 0; i < b; ++i) cin >> mic[i];

    int* dis = new int[m];

    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        dis[i] = fri[x - 1] + mic[y - 1] - c;
    }
    cout << min(*min_element(dis, dis + m), *min_element(fri, fri+a)+*min_element(mic, mic+b));
    return 0;
}   