#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 200005;
int n;
vector<pair<ll, ll> > v;
ll memo[2005][2005];
int arr[2005];
ll solve( int i, int l) {
if (i==n) {
return 0LL;
}
if (memo[i][l] != -1) {
return memo[i][l];
}
ll r=n-(i-l)-1;
 return memo[i][l] = max(
    1LL * v[i].first * abs(v[i].second - l) + solve(i+1, l+1),
    1LL * v[i].first * abs(v[i].second - r) + solve(i+1, l)
  );
 
}
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
cin >> n;

for (int i = 0; i < n; i++)
cin >> arr[i];
for (ll i = 0; i < n; i++) {
v.push_back({arr[i], i});
}
memset(memo, -1, sizeof memo);
sort(v.begin(), v.end());
reverse(v.begin(), v.end());

ll ans= solve( 0, 0);
cout<<ans<<endl;
return 0;
 
}