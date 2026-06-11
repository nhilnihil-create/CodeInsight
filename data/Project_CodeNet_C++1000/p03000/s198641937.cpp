#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int count = 0, y = 0;
    for (int i = 0; i < n && y <= x; i++) {
        count++;
        y += v[i];
    }
    if (y <= x)
        count++;
    cout << count << endl;
}