#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m, v, p, a[100005];

bool check(int s){
	if(a[s] + m < a[p]) return 0;
	int op = 0;
	for(int i = p; i < s; i++){
		op += (a[s] + m) - a[i];
	}
	op += ((p - 1) * m) + ((n - s + 1) * m);
	if(op >= m * v){
		return 1;
	}
	return 0;
}

main(){
	cin >> n >> m >> v >> p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}                              
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0; 
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			l = mid + 1;
			ans = mid;  
		}
		else {
			r = mid - 1;
		}
	}
	cout <<	ans;
}