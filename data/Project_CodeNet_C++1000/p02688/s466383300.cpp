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
    int n, k; cin >> n >> k;
    bool has[n + 1];
    mm(has);
    for(int i = 0; i < k; i++){
        int d; cin >> d;
        for(int j = 0; j < d; j++){
            int a; cin >> a;
            has[a] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!has[i])ans++;
    }
    cout << ans;
    return 0;
}
