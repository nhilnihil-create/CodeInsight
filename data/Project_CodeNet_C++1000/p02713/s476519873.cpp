#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int k;
	cin >> k;

	int ans = 0;
	for(int a=1;a<=k;a++){
		for(int b=1;b<=k;b++){
			for(int c=1;c<=k;c++){
				int g = __gcd(a,__gcd(b,c));
				ans += g;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
