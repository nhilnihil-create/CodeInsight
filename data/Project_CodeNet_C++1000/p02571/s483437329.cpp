#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repab(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
#define endl "\n"

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//--//--//--//--//--//--//--//--//--//--//--//

int main() {
    string s, t;
    cin >> s >> t;
 
    int ans = t.size();
 
    for (int start = 0; start <= s.size() - t.size(); start++){
        int diff = 0;
        for (int i = 0; i < t.size(); i++){
            if (t[i] != s[start + i]){
                diff++;
            }
        }
        ans = min(ans, diff);
    }
 
    cout << ans << endl;
}