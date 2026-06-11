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
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    int ans[n];
    for(int i = 0; i < n - 1; i++){
        ans[arr[i].second] = arr[n - 1].first;
    }
    ans[arr[n - 1].second] = arr[n - 2].first;
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
