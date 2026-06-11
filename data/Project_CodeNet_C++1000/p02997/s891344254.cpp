#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int x = (N - 1) * (N - 2) / 2;

    if(K > x) {
        cout << -1 << endl;
        return 0;
    }

    int ans = N - 1;
    vector<p> a;

    for(int i = 1; i <= ans; i++) {
        a.push_back(make_pair(i, N));
    }

    int count = 0;
    int f = 1;
    int b = 2;

    while(count < x - K) {
        a.push_back(make_pair(f, b));
        b++;
        if(b == N) {
            f++;
            b = f + 1;
        }
        count++;
    }

    ans += count;

    cout << ans << endl;

    for(int i = 0; i < ans; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
}