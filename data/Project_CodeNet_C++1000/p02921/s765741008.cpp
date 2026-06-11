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
    string S, T;
    cin >> S >> T;
    int ans = 0;
    rep(i, 3) {
        if (S[i] == T[i])
            ans++;
    }
    cout << ans << endl;
}