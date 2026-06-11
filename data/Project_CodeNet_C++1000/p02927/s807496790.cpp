#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;


long long mod = 1000000007;
int main(){
	//freopen("i.txt","r",stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int m, d;
	cin >> m >> d;
	int ans = 0;
	for(int i = 10;i <= d;i++){
		int a = i % 10;
		int b = i / 10;
		if(a >= 2 && b >= 2 && a * b <= m) ans++;
	}
	cout << ans;
}
