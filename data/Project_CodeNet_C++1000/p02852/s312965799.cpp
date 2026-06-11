#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int i = s.size();
    vector<int> ans;

    int now = n;

    while(now > 0){
        int p = min(now, m);
        bool tmp = 0;
        for(int i = p; i >= 1; i--){
            if (s[now-i] == '0'){
                tmp = 1;
                now -= i;
                ans.push_back(i);
                break;
            }
        }
        if (!tmp) {
            cout << -1 << endl;
            return 0;
        }
    }

    rrep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;

    return 0;
}