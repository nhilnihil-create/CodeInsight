#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 200005;
int n;
vector<pair<int, int> > v;
ll memo[2000][2000];
ll solve(int *arr, int i, int l, int r) {
if (i==n) {
return 0;
}
if (memo[l][r] != -1) {
return memo[l][r];
}
ll ans1 = solve(arr, i + 1, l + 1, r) + (1LL * v[i].first * abs(v[i].second - l));
ll ans2 = solve(arr, i + 1, l, r - 1) + (1LL * v[i].first * abs(v[i].second - r));
return memo[l][r] = max(ans1, ans2);
 
}
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
cin >> n;
int arr[2005];
for (int i = 0; i < n; i++)
cin >> arr[i];
for (int i = 0; i < n; i++) {
v.push_back({arr[i], i});
}
memset(memo, -1, sizeof memo);
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
// for (int i = 0; i < n; i++) {
// cout << v[i].first << " " << v[i].second << endl;
// }
cout<<solve(arr, 0, 0, n - 1);
//cout<<ans<<endl;
return 0;
 
}