#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n,k;
	cin >> n >> k;



	cout << min(n%k,k-(n%k)) << endl;

	return 0;
}
