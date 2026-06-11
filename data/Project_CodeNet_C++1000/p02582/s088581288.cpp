#include <bits/stdc++.h>
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;

int dr[] = {0, 0, -1, +1, -1, -1, +1, +1};
int dc[] = {-1, +1, 0, 0, -1, +1, -1, +1};

int main(){
    string s; cin >> s;
    int ans = 0;
    if(s == "RRR")
        ans = 3;
    else if((s[0] == 'R' && s[1] =='R') || (s[1] == 'R' && s[2] =='R'))
        ans = 2;
    else if(s[0] =='R' || s[1] == 'R' || s[2] =='R')
        ans = 1;
    cout << ans << endl;
}

