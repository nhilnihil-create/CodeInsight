#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100

int main()
{
	int arr[5];
	int pos = -1;
	for(int i=0; i<5; i++) {
		cin >> arr[i];
		if(arr[i]==0) pos = i+1;
	}
	cout << pos << endl;
	return 0;
}
