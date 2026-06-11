#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int M,D;
	cin >> M >> D;

	int ans = 0;

	for(int m=1;m<=M;m++){
		for(int d=1;d<=D;d++){
			int d1 = d%10;
			int d10 = d/10;
			if(d1>=2 && d10>=2 && d1*d10==m) ans++;
		}
	}
	
	cout << ans << endl;

	return 0;
}
