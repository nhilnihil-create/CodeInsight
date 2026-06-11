#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define L(i,n) for(int i=0;i<n;i++)
#define ull unsigned long long 
#define endl '\n'   
using namespace std;
const int N = 1e5+7;
int  n, a,b,x;
ull sum = 0;
int main()
{
	IO
		cin >> n;
	int  arr[N];
	L(i, n+1)
		cin >> arr[i];
	L(i, n)
	{
		cin >> x;
		sum += min(x, arr[i]);
		x -= min(x, arr[i]);
		arr[i] -= min(x, arr[i]);
		if (x > 0 )
		{
			sum += min(arr[i+1],x);
			arr[i + 1] -= min(arr[i + 1], x);
		}
		
	}
	cout << sum << "\n";
}