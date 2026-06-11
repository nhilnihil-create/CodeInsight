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
#define int ll

int32_t main(){
    FAST
    int a, b; cin >> a >> b;
    map<int, bool> has;
    for(int i = 2; i*i <= a; i++){
        if(a%i == 0)has[i] = 1;
        while(a%i == 0){
            a /= i;
        }
    }
    if(a != 1){
        has[a] = 1;
    }
    int ans = 1;
    for(int i = 2; i*i <= b; i++){
        if(b%i == 0){
            if(has[i])ans++;
        }
        while(b%i == 0){
            b /= i;
        }
    }
    if(b != 1){
        if(has[b])ans++;
    }
    cout << ans;
    return 0;
}
