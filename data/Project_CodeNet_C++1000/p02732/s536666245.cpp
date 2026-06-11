#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fr front
#define fi first
#define sc second
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	ll ans = 0;
	int n; scanf("%d", &n);
	map <int, int> ct;
	map <int, int>::iterator it;
	
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ct[a[i]]++;
	}
	for(it = ct.begin(); it != ct.end(); ++it){
		ans += 1LL * (it -> sc) * (it -> sc - 1) / 2;
	}
	for(int i = 0; i < n; i++){
		printf("%lld\n", ans - 1LL * ct[a[i]] + 1);
	}
}