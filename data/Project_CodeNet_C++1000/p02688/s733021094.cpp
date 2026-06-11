#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 300006;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set < int > s;
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int y;
            cin >> y;
            s.erase(y);
        }
    }
    cout << s.size() << '\n';
    return 0; 
}
 