#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	int a[100001];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	if(n == 2){
		cout << a[1] - a[0] << endl;
		cout << a[1] << " " << a[0] << endl;
		return 0;
	}
	int sum1 = accumulate(a + 1, a + n, 0);
	int sum2 = a[0];
	int ans = sum1 - sum2;
	int ind = 0;
	for(int i = 1; i < n - 1; i++){
		sum1 -= a[i];
		sum2 += a[i];
		if(sum1 - sum2 > ans){
			ans = sum1 - sum2;
			ind = i;
		}
	}
	cout << ans << endl;
	int tmp = a[0];
	for(int i = ind + 1; i < n - 1; i++){
		cout << tmp << " " << a[i] << endl;
		tmp -= a[i];
	}
	cout << a[n - 1] << " " << tmp << endl;
	tmp = a[n - 1] - tmp;
	for(int i = 1; i <= ind; i++){
		cout << tmp << " " << a[i] << endl;
		tmp -= a[i];
	}
}
