#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair

const int MOD = 1000000007;
const int N = 1e5 + 18;



int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {


        string s, t;
        cin >> s >> t;
        int sum = 0;
        for (int i = 0; i < min(s.size(), t.size()); i++) {
            if (s[i] != t[i]) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;

}

