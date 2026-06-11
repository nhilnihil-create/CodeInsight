#include<bits/stdc++.h>
using namespace std;

int G(int x, int N){
	if(x%10 == 0) return 0;

	int res = 0;

    int F = x%10;
	while(x > 9) x /= 10;

	if(F == x) ++res;
    
	for(int tmp = 10; true; tmp *= 10){
		for(int i = 0; i < tmp/10; ++i)
			if(F*tmp + x + i*10 > N) return res;
			else ++res;
	}

	return 0;
}

int main(){
	int n; cin >> n;
	int ans = 0;

	for(int i = 1; i <= n; i++)
		ans += G(i, n);

	cout << ans << endl;
	return 0;
}
