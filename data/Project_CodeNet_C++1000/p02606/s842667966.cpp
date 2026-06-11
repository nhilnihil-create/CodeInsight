#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define mod 1000000007
const int INF=(1LL<<60)-1;
int32_t main(){
    SPEED;
    int l, r, d;
    cin >> l >> r >> d;
    if(l % d == 0) cout << r/d - l/d + 1;
    else cout << r/d - l/d;
}