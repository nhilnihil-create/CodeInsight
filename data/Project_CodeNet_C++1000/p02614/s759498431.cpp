#include<bits/stdc++.h>
using namespace std;

#define F                   first
#define S                   second
#define int                 long long int
#define pb                  push_back
#define mp                  make_pair
#define pii                 pair<int,int>
#define vi                  vector<int>
#define mii                 map<int,int>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int> >
#define mod                 1000000007
#define endl                '\n'
#define rep(i,a,b)            for(int i=a;i<b;i++)
int n, m, parth;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool helper(int x, int y, vector<vector<char>> b) {
    int i = 0;
    int k = 1;
    while (i < n) {
        if (x & (k << i)) {
            rep(z, 0, m) {
                b[i][z] = 'r';
            }
        }
        i++;
    }
    int j = 0;
    k = 1;
    while (j < m) {
        if (y & (k << j)) {
            rep(z, 0, n) {
                b[z][j] = 'r';
            }
        }
        j++;
    }
    int ans = 0;
    rep(k, 0, n) {
        rep(l, 0, m) {
            //cout << b[k][l] << " ";
            if (b[k][l] == '#') {
                ans++;
            }
        }
        //cout << endl;
    }
    // if (ans == parth) {
    //     rep(k, 0, n) {
    //         rep(l, 0, m) {
    //             cout << b[k][l] << " ";
    //             // if (b[k][l] == '#') {
    //             //     ans++;
    //             // }
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;

    // }


    return ans == parth;
}
int32_t main()
{
    c_p_c();
    cin >> n >> m >> parth;
    vector<vector<char>> a(n, vector<char>(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    vector<int> r;
    vector<int> c;
    rep(i, 0, (int)pow(2, n)) {
        r.pb(i);
    }
    rep(i, 0, (int)pow(2, m)) {
        c.pb(i);
    }
    int ans = 0;
    for (auto x : r) {
        for (auto y : c) {
            vector<vector<char>> b = a;
            if (helper(x, y, b)) {
                ans++;
            }
            //cout << " " << x << " " << y << endl;
        }
    }
    //helper(1, 0, a);

    cout << ans << endl;
    //cout << "eheill-";

    return 0;
}