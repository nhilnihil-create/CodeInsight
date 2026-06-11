#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n,m;
	cin >> n >> m;

	cout << n*(n-1)/2 + m*(m-1)/2 << endl;

	return 0;
}
