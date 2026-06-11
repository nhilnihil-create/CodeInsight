#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    set<int> se;
    rep(i, N){
        int a;
        cin >> a;
        se.insert(a);
    }
    if (se.size() == N){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}