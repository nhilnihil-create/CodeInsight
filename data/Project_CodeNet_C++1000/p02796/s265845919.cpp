#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, T t){return v2<T>(r, vector<T>(c, t));}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> r(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        r[i] = {a+b, a-b};
    }
    sort(r.begin(), r.end());

    int ans = 0;
    int b;
    for(int i = 0; i < n; i++){
        if(!ans || r[i].second >= b){
            ans++;
            b = r[i].first;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
