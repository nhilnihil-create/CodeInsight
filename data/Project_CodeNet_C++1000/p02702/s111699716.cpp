#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, T t){return v2<T>(r, vector<T>(c, t));}

void solve(){
    string s;
    cin >> s;
    int n = s.length();

    int ans = 0;
    array<int, 2019> seen = {};
    seen[0] = 1;
    int sum = 0;
    int mult = 1;
    for(int i = n-1; i >= 0; --i){
        sum = (sum + mult*(s[i]-'0')) % 2019;
        ans += seen[sum];
        seen[sum]++;
        mult = (mult*10) % 2019;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
