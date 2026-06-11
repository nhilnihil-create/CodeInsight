#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; scanf("%d", &n);
	vector<vector<int> > a(10, vector<int> (10, 0));
	for(int i = 1; i <= n; i++){
		string s = to_string(i);
		int n = s.size();
		a[s[0] - '0'][s[n - 1] - '0']++;
	}
	int ans = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) ans += a[i][j] * a[j][i];
	}
	printf("%d\n", ans);
}