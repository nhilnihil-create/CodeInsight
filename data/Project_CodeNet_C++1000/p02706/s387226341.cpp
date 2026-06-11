#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int n,m;
	cin >> n >> m;
	int a[m];
	for(int i=0;i<m;i++) cin >> a[i];

	int sum = 0;
	for(int i=0;i<m;i++) sum += a[i];
	
	printf("%lld\n", n-sum>=0 ? n-sum : -1);


	return 0;
}
