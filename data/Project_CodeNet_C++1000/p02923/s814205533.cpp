#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int a[100005], n, m;

int main(){
	int i, j;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0,c = 0;
	for(i=1;i<n;i++){
		if(a[i] <= a[i-1])c++;
		else c = 0;
		ans = max(c, ans);
	}
	cout << ans;
}