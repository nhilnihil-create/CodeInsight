#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
	
int main(){
	int n, x;
	cin >> n >> x;
	int sum = 0, cnt = 0;
	if(sum <= x)cnt++;
	for(int i = 1; i <= n; i++){		
		int t; cin >> t; sum += t;
		if(sum <= x)cnt++;
	}
	cout << cnt << endl;
	return 0;
}                  














