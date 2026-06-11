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

/* --------------------------------------------------- */

int main() {
    string s;
    cin >> s;
    int ans = 0;
    if(s == "RRR") ans = 3;
    else if(s == "SRR" || s == "RRS") ans = 2;
    else if(s == "SSS") ans = 0;
    else ans = 1;

    cout << ans << endl;
    return 0;
}