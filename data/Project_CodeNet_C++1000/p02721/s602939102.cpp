#include <bits/stdc++.h>

#define MAXN 200010
#define ll long long
#define mod 1000000007

using namespace std;

int n, m, k, c;
int ans, tot;

int a[MAXN];

string s;

int main(){
	int t;
	scanf("%d%d%d", &n, &k, &c);
	cin >> s;
	
	
	int i = n, num = 0;
	while (i >= 1) {
		if (s[i - 1] == 'o') {
			num++;
			a[i]++;
		i -= c;
		}
		i--;
	}
	
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
	
	if (num != k) {
//		cout << num << endl;
		return 0;
	}
	
	i = 1;
	while (i <= n) {
		if (s[i - 1] == 'o') {
			if (a[i] == 1) cout << i << endl;
		i += c;
		}
		i++;
	}

	return 0;
}
