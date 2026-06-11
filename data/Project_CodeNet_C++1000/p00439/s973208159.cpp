#include <iostream>
using namespace std;

int main()
{
	int n,k,a[100000],temp;
	while(cin >> n >> k,n || k){
		cin >> a[0];
		for(int i = 1;i < n;i++){
			cin >> temp;
			a[i] = a[i - 1] + temp;
		}
		temp = 0;
		for(int i = 0;i < n - k;i++)
			if(temp < a[i + k] - a[i])
				temp = a[i + k] - a[i];
		cout << temp << endl;
	}
	return 0;
}