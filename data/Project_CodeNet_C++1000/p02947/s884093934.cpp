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
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sort(v[i].begin(), v[i].end());
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        string s = v[i];
        ll cnt = 0;
        while(s == v[i]){
            i++;
            cnt++;
            if(i == n)break;
        }
        i--;
        ans += cnt*(cnt - 1)/2;
    }
    cout << ans;
    return 0;
}
