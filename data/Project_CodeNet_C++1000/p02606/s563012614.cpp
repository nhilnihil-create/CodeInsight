#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;

main(){
	int l,r,d;
	cin >> l >> r >> d;

	int ans = 0;
	for(int i=l;i<=r;i++){
		if(i%d==0) ans++;
	}

	cout << ans << endl;

	return 0;
}
