#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	if(a- 2*b <= 0)
		cout << 0;
	else
		cout << a -2*b;
	return 0;
}