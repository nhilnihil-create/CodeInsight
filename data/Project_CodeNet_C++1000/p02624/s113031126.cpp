#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> d(n+1,0);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j+=i){
			d[j]+=1;
		}
	}
	long long int ans = 0;
	for(int i = 1; i <= n; i++)
		ans+= 1ll * i * d[i];
	cout << ans << "\n";	
	return 0;
}
