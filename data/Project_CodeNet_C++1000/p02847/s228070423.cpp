#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    string s;
    cin >> s;
    int ans;
    if(s == "SUN") ans = 7;
    else if(s == "MON") ans = 6;
    else if(s == "TUE") ans = 5;
    else if(s == "WED") ans = 4;
    else if(s == "THU") ans = 3;
    else if(s == "FRI") ans = 2;
    else ans = 1;
    cout << ans << endl;
    return 0;
}