#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second

int main(){
    FAST
    int n, m; cin >> n >> m;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    bool good[n + 1];
    memset(good, 1, sizeof(good));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        if(h[a] <= h[b])good[a] = 0;
        if(h[b] <= h[a])good[b] = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(good[i])ans++;
    }
    cout << ans;
    return 0;
}
