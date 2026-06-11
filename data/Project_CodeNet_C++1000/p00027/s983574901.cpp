#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define first first
#define second se
using namespace std;
typedef pair<int, int> P;
typedef vector<int> vi;

int ds[13] = {0, 1, -1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
string st[7] =  {"Monday",
                "Tuesday",
                "Wednesday",
                "Thursday",
                "Friday",
                "Saturday",
                "Sunday"};

signed main(){
    int m, d;
    while(cin >> m >> d){
        if(m + d == 0) break;
        int s = 30 * (m - 1) + d;
        rep(i, 1, m){
            s += ds[i];
        }
        s = (s + 2) % 7;
        o(st[s]);
    }
}