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
    int n; cin >> n;
    int ans = 0;
    for(int i = 2; i * i <= n; i++){
        int cnt = 0;
        while(n%i == 0){n /= i; cnt++;}
        int a = 1;
        while(cnt){
            cnt -= a;
            if(cnt < 0)break;
            a++;
        }
        a--;
        ans += a;
    }
    if(n != 1){
        ans++;
    }
    cout << ans << endl;
    return 0;
}
