#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int main()
{
	long long a, b = 0, c = 0;
	long long ans = 1e18;
	cin >> a;
	for(ll i =1; i*i<=a; i++){
		if(a%i == 0){
			b = i-1;
			c = a/i - 1;
			ans = min(b+c, ans);
		}
		else{
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}