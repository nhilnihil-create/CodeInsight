#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m,d, ans=0;
	cin >> m >> d;
	for(int i=1;i<=m;i++){
		for(int j=22;j<=d;j++){
			if((j%10)*((int)j/10) == i && (j%10) >= 2 && ((int)j/10) >= 2) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}