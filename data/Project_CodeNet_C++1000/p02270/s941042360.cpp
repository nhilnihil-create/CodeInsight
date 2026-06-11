#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll n,k;
int a[100000];
int check(ll m) {
	int i=0, j;
	for (j = 0; j < k; j++) {
		ll num = 0;
		while (num + a[i] <= m) {
			num += a[i];
			i++;
			
			if (i == n) {
				return n;
			}

		}
	}
	return i;
}



int Search() {
	ll l = 0, r = 100000*10000;
	ll mid;
	while (r - l > 1) {
		mid = (l + r) / 2;
		int m = check(mid);
		if (m >= n) {
			r = mid;
		}
		else {
			l = mid;
		}
		
	}
	return r;

}


int main()
{
	

	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	
		
		
	}
	ll p = Search();
	cout << p<<endl;






	return 0;
}
