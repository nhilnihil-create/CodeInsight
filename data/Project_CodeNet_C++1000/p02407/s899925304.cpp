#include<iostream>
using namespace std;
int main(void)
{
	int i,n,a[100];
	
	cin >> n;

	for(i=0 ; i<n ; i++){
		cin >> a[i];
	}

	for(i-=1 ; i>0 ; i--){
		cout << a[i] << " ";
	}

	cout << a[0] << endl;

	return 0;
}