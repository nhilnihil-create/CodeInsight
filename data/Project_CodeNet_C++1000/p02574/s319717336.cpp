#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;
int n, a[1000005], u[1000005];

int main() {

    scanf("%d", &n);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        g = __gcd(g, a[i]);
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                u[j]++;
                while (a[i] % j == 0)a[i] /= j;
            }
        }
        u[a[i]]++;
    }
    if (g > 1) {
        cout << "not coprime\n";
        return 0;
    }
    for (int i = 2; i <= (int) 1e6; i++) {
        if (u[i] > 1) {
            cout << "setwise coprime\n";
            return 0;
        }
    }
    cout << "pairwise coprime\n";
    return 0;
}