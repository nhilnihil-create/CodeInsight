#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int n,k;
vector<int> a;

bool ok(int md){
	int cnt = 0;
	for(int  i = 0; i < n; i++){
		cnt += (a[i] - 1) / md;
	}
	return cnt <= k;
}

int main(){
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int low = 1;
	int high = 1e9;
	int ans = 1e9;
	while(low <= high){
		int md = (low + high) / 2;
		if(ok(md)){
			high = md - 1;
			ans = min(ans,md);
		}else{
			low = md + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
