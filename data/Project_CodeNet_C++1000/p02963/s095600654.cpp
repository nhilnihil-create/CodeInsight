#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
	ll S;
	cin >> S;
	
	const ll ten9 = 1000000000;
	
	cout << 0 << " " << 1 << " ";
	cout << ten9 << " " << 0 << " ";
	if( S < ten9 * ten9){
		cout << S % ten9 << " " << 1 + (S / ten9)<< endl;
	}else{
		cout << ten9 << " " << ten9 << endl;
	}
	
	return 0;
}