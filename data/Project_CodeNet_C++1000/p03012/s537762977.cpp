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
    int n; cin >> n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int s1 = 0;
        for(int j = 0; j <= i; j++){
            s1 += arr[j];
        }
        int s2 = sum - s1;
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans << endl;
    return 0;
}
