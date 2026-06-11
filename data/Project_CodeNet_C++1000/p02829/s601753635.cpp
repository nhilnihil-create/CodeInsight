#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000009
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;


int main()
{

	io;
	
	int a, b; cin >> a >> b;
	int arr[4] = { 0 };
	arr[a] = 1;
	arr[b] = 1;
	for (int i = 1; i <= 3; i++)
		if (!arr[i])
			cout << i;
}

