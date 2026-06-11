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

int main(){
    FAST
    ll n; cin >> n;
    string alpha = "zabcdefghijklmnopqrstuvwxy";
    string ans = "";
    while(n > 0){
        int a = n%26;
        ans += alpha[a];
        if(a == 0)n--;
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
