#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

ll a[N], cum[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int c = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1') c++;
        else{
            if(c >= m) return cout << -1, 0;
            c = 0;
        }
    }
    reverse(s.begin(), s.end());
    vector<int> v;
    int ans = 0;
    for(int i = min(m, n); i != n; i = min(i + m, n)){
        int kam = m;
        while(s[i] == '1') i--, kam--;
        v.push_back(kam);
        ans += kam;
    }
    v.push_back(n - ans);
    reverse(v.begin(), v.end());
    for(auto i: v) cout << i << ' ';

    return 0;
}
