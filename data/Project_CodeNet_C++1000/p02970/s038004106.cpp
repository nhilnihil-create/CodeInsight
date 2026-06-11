#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
	FastIO
	lld n, d;
	cin >> n >> d;
	if (d <= n){
		lld count = 0;
		lld i;
		for(i = d+1; i <= n; i++){
			i += (2*d);
			count += 1;
		}
		lld j = i-(2*d)-1;
		if (j+d < n){
			count += 1;
		}
		cout << count;
	}
	else{
		cout << "1";
	}
	return 0;
}