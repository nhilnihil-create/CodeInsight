#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

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
    int n, k; cin >> n >> k;
    ld arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ld num = arr[i];
        arr[i] = arr[i]* (arr[i] + 1);
        arr[i] /= 2.0;
        arr[i] /= num;
    }
    ld sum = 0;
    for(int i = 0; i < k; i++){
        sum += arr[i];
    }
    ld ans = sum;
    int p1 = 0;
    for(int i = k; i < n; i++){
        sum -= arr[p1];
        sum += arr[i];
        ans = max(ans, sum);
        p1++;
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}
