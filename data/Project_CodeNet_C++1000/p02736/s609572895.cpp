#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100010;

using namespace std;

int C(int n, int k)
{
        if((n & k) == k) return 1;
        return 0;
}

int solve(string s)
{
        int res = 0, n = s.size();
        for(int i = 0; i < n; i++){
                if(s[i] & 1) res ^= C(n - 1, i);
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n;
        string s;
        cin >> n >> s;
        for(auto &c: s) c -= '1';
        int res = solve(s);
        if(res == 1){
                cout << res << '\n';
                return 0;
        }
        bool shit = false;
        for(int i = 0; i < n; i++){
                if(s[i] == 1) shit = true;
                else if(s[i] == 2) s[i] = 1;
        }
        if(shit) cout << 0 << "\n";
        else cout << 2 * solve(s) << "\n";
}
