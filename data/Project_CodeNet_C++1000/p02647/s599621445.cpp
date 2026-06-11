#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;

#define fbo find_by_order
#define ook order_of_key
#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

// /mnt/c/Users/vince/Desktop/POST-IOI/Codeforces/Regular/670

int n, k;
int A[200003];
int pref[200003];

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	// printf("%lld\n", rng());

	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &A[i]);

	for(int cnt = 1; cnt <= k; cnt++)
	{
		memset(pref, 0, sizeof pref);
		for(int i = 1; i <= n; i++)
		{
			pref[max(1,i-A[i])]++;
			pref[min(n, i+A[i])+1]--;
		}
		bool bol = 1;
		for(int i = 1; i <= n; i++)
		{
			pref[i] += pref[i-1];
			A[i] = pref[i];
			if(A[i] != n)
				bol = 0;
		}
		if(bol)
		{
			// printf("%d\n", cnt);
			break;
		}
		// for(int i = 1; i <= n; i++)
			// printf("%d%c", A[i], (i == n)? '\n' : ' ');
	}
	for(int i = 1; i <= n; i++)
		printf("%d%c", A[i], (i == n)? '\n' : ' ');
}


