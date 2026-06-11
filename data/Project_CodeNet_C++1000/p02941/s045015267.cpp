#include <bits/stdc++.h>

using namespace std;

long long arr[200005];
long long target[200005];

long long n;

int main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 0;i < n;i++) cin >> target[i];
	for(int i = 0;i < n;i++) cin >> arr[i];
	
	
	queue<int> things;
	
	long long ans = 0;
	
	for(int i = 0;i < n;i++) things.push(i);
	
	while(!things.empty()){
		int u = things.front(); things.pop();
		
		long long A, B, C;
		B = arr[u];
		
		if(u == 0) A = arr[n-1];
		else A = arr[u-1];
		
		if(u == n-1) C = arr[0];
		else C = arr[u+1];
		
		//cout << u << " " << A << " " << B << " " << C << endl;
		
		if(B <= A + C) continue;
		
		//cout << u << "F" << endl;
		
		long long newB = target[u]; ///the lowest possible value it should go to
		long long times = (B - newB) / (A + C); ///how many times to subtract
		
		ans += times;
		arr[u] = B - times * (A + C);
		
		if(u == 0) things.push(n-1);
		else things.push(u-1);
		
		if(u == n-1) things.push(0);
		else things.push(u+1);
	}
	
	for(int i = 0;i < n;i++) if(arr[i] != target[i]) ans = -1;
	cout << ans;
}
