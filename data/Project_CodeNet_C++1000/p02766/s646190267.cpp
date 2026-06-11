#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	ll n,k;
	cin >> n >> k;

	int ans = 1;
	ll tmp = k;
	while(n>=tmp){
		ans++;
		tmp*=k;
	}

	cout << ans << endl;


	return 0;
}
