#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int n;
	cin >> n;

	int ans = 0;
	for(int i=1;i<=n;i++){
		int j=n-i;
		if(j<=i) break;
		else ans++;
	}

	cout << ans << endl;

	return 0;
}
