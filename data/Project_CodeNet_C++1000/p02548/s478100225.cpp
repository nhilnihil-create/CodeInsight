#include <bits/stdc++.h>
using namespace std;	


int main()
{
	int a;
	cin >> a;
	int count = 0;
	for(int i = 1;i<=a-1;i++){
		count += (a-1)/i;
	}
	cout << count;
	return 0;
}
