#include <bits/stdc++.h>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	int n;
	string s;

	scanf("%d", &n);

	cin >> s;

	if (n%2==1){
		printf("No\n");
	} else {
		for (int i = 0, j = n/2; i < n/2 && j < n; i++, j++){
			if (s[i] != s[j]){
				printf("No\n");
				return 0;
			}
		}
		printf("Yes\n");
	}

	return 0;
}