/************************************
/ AUTHOR : YATHARTH GOSWAMI         /  
/ ALIAS : hacker_yg                 /
/ INSTITUTE : IIT Kanpur            /
************************************/
//          TEMPLATE                //

#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265359

using namespace std;

/*ll powMod(ll a, ll y)
{
    ll ans = 1;
    
    while (y > 0) 
    { 
        if (y & 1) 
            ans = (ans*a) % MOD; 
  
        y = y>>1;
        a = (a*a) % MOD; 
    } 
    return ans;
}*/

/*ll modInv(ll a)
{
    return powMod(a, MOD-2);	
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int h, w, m;
    cin >> h >> w >> m;
    vector <pair <int, int>> v(m);
    for (int i = 0; i < m; i++) cin >> v[i].F >> v[i].S;
    int ans = 0, maxr = -1, maxcol = -1;
    map <int, int> m1, m2;
    for (int i = 0; i < m; i++) {
        m1[v[i].F]++; m2[v[i].S]++;
    }
    for (int i = 1; i <= h; i++) maxr = max(maxr, m1[i]);
    for (int i = 1; i <= w; i++) maxcol = max(maxcol, m2[i]);
    ll count = 0, a = 0, b = 0;
    for (int i = 1; i <= h; i++) if (m1[i] == maxr) a++;
    for (int i = 1; i <= w; i++) if (m2[i] == maxcol) b++;
    for (pair<int, int> p : v) {
        if (m1[p.F] == maxr && m2[p.S] == maxcol) count++;  
    }
    if (count < a*b) cout << maxr + maxcol << endl;
    else cout << maxr + maxcol - 1 << endl;
    return 0;
}


