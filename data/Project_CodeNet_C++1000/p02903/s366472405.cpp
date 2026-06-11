#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1007;
bool ans[N][N];
int want[N];
bool comp(int i, int j) {
    return want[i] > want[j];
}   
void print(int n, int m, int a, int b, int x, int y) {
    vector <int> per;
    for (int i = 0; i < m; ++i)
        per.app(i);

    for (int i = 0; i < y; ++i)
        want[i] = b;
    for (int i = y; i < m; ++i)
        want[i] = n - b;

    for (int i = 0; i < n; ++i) {
        sort(all(per), comp);
        
        int add;
        if (i < x)
            add = a;
        else
            add = m - a;

        for (int j = 0; j < add; ++j) {
            ans[i][per[j]] = 1;
            --want[per[j]];
        }
    }   

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }                     
        cout << endl;
    }   
    exit(0);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int k1 = i * a + (n - i) * (m - a);
            int k2 = j * b + (m - j) * (n - b);
            if (k1 == k2) {
                print(n, m, a, b, i, j);
            }   
        }   
    }   
    exit(1);
}