#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long arr[n+1];

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	for(int i = 1; i <= n; i++){
		if(arr[i] != i){
			swap(arr[i], arr[arr[i]]);
			break;
		}
	}

	for(int i = 1; i <= n; i++){
		if(arr[i] != i){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}