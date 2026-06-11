// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lli long long int
#define all(c) c.begin(),c.end()
#define lower(c) tolower(c)
#define upper(c) toupper(c)
#define MAX(c) *max_element(c.begin(),c.end())
#define MIN(c) *min_element(c.begin(),c.end())
#define len(c) c.size()
const int MOD = 1000000007;
const int MX = 2e5 + 5;
const int INF = 1e9 + 10;
const lli LINF = 1e18;

void solve() {
	string s;
    cin >> s;
    int ans;
    if(s == "SUN")ans = 7;
    else if(s == "MON")ans = 6;
    else if(s == "TUE")ans = 5;
    else if(s == "WED")ans = 4;
    else if(s == "THU")ans = 3;
    else if(s == "FRI")ans = 2;
    else if(s == "SAT")ans = 1;
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
