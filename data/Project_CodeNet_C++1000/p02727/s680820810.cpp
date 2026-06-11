#include <bits/stdc++.h>
using namespace std;
#define LL long long 
#define LLU long long unsigned
#define rarr(arr, n) for(int aab = 0; aab < n; aab++){cin >> arr[aab];}
#define parr(arr, n) for(int aab = 0; aab < n; aab++){cout << arr[aab] << " ";}
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n";

#define freopen freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);ios_base::sync_with_stdio(0);cin.tie(0);

int main(){	
	long long int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	long long int aa[a], bb[b], cc[c];
	rarr(aa, a);
	rarr(bb, b);
	rarr(cc, c);
	sort(aa, aa + a, greater<>()), sort(bb, bb + b, greater<>());
	vector<long long int> v1;
	for(int i = 0; i < x; i++) v1.pb(aa[i]);
	for(int i = 0; i < y; i++) v1.pb(bb[i]);
	for(int i = 0; i < c; i++) v1.pb(cc[i]);
	sort(all(v1), greater<>());
	long long int ans = 0;
	for(int i = 0; i < x + y; i++) ans += v1[i];
	cout << ans;
}
