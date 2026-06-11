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
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int cnt = 0;
    for (int i = 1; i < n-1; i++) 
    {
        if (max({v[i - 1], v[i], v[i + 1]}) != v[i] &&
            min({v[i - 1], v[i], v[i + 1]}) != v[i])
            cnt++;
    }
    cout << cnt << endl;
}