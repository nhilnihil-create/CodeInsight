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
    int n;
    cin >> n;
    vector<int> v(n - 1);
    rep(i, n - 1) cin >> v[i];
    int sum = v[0];
    rep(i, n - 1) {
        sum += min(v[i], v[i - 1]);
    }
    sum += v.back();
    cout << sum << endl;
}