#include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lli long long int
#define all(c) c.begin(),c.end()
#define lower(c) tolower(c)
#define upper(c) toupper(c)
#define MAX(c) *max_element(c.begin(),c.end())
#define MIN(c) *min_element(c.begin(),c.end())
#define len(c) c.size()
const int MOD = 1000000007;
const int MX = 2e5 + 5;
const int INF = 1e9 + 10;
const lli LINF = 1e18;

void solve() {
	int n;
	cin >> n;
	vi a;
	fo(i,n){int t;cin>> t;a.pb(t);}
	sort(all(a));
	int ans = 0;
	fo(i,n){
		for(int j = 0;j<i;j++){
			for(int k=0;k<j;k++){
				if(a[k]!=a[j]&&a[i]!=a[j]&&a[k]+a[j]>a[i]){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

