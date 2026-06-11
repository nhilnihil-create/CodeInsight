#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    int additional = ((n-1)*(n-2))/2-k;
    if (additional < 0) {
        cout << -1;
        return;
    }
    cout << n-1+additional << '\n';
    fo(i, n-1) printf("%d %d\n", n, i+1);
    int start = 1;
    int end = 2;
    while (additional--) {
        printf("%d %d\n", start, end);
        end++;
        if (end == n) {
            start++;
            end = start+1;
        }
    }

}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}