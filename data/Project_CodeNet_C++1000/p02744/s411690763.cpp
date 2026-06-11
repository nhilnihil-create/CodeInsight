#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

int N;

void dfs(string s, char mx){
    if (s.size() == N){
        cout << s << "\n";
    } else {
        for (char i='a';i<=mx;i++){
            dfs(s + i, (i==mx)?(mx+1):mx);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    dfs("", 'a');
}