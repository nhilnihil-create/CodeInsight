#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,ans=0;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i += 1){
		for(int j = 20 ; j <= m ; j += 1){
			if(j % 10 >= 2){
				int t = j;
				t /= 10;
				if((t%10) * (j%10) == i){
					ans += 1;
				}
			}
		}
	}
	cout << ans << endl;
}