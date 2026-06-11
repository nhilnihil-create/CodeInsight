#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() {

    zoom;
    ll X, Y;
    cin >> X >> Y;
    ll look[3] = {300000, 200000, 100000};
    ll ans = 0;
    if(X <= 3)
    	ans += look[X - 1];
    if(Y <= 3)
    	ans += look[Y - 1];
    if(X == 1 && Y == 1)
    	ans += 400000;
    cout << ans;
    return 0;
}