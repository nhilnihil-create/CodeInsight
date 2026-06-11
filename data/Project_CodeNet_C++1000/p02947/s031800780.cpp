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
#define int ll

int32_t main(){
    FAST
    int n; cin >> n;
    map<string, int> has;
    string arr[n];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        sort(s.begin(), s.end());
        arr[i] = s;
        has[s]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += has[arr[i]]*(has[arr[i]] - 1)/2;
        has[arr[i]] = 1;
    }
    cout << ans;
    return 0;
}
