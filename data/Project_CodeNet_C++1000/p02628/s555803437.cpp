#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int x, y,arr[1000],sum=0;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + x);
	for (int i = 0; i < y; i++) {
		sum = sum + arr[i];
	}
	cout << sum;
}