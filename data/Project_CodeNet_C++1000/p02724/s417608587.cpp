#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int x;
	cin >> x;

	cout << (x/500)*1000 + (x%500)/5*5 << endl;

	return 0;
}
