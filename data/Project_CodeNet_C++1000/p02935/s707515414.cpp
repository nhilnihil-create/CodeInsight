#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    double ans = v[0];
    for (int i = 1; i < N; i++) {
        ans = (ans + v[i]) / 2.0;
    }
    printf("%.12f\n", ans);
}