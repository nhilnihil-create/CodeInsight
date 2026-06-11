#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;

vector<int> num;
ll d,a,b, k, c,m,mod=1e9+7;
ll DP[20][2520][2];
int mxlids,cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>a>>b>>c>>d;

    ll mx = a*c;

    mx=max(mx,a*d);
    mx=max(mx,b*d);
    mx=max(mx,b*c);

    cout<<mx;
    return 0;
}