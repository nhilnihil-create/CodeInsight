#include<iostream>
using namespace std;

int main() {
	int i , j , k=0 , n ;
	cin >> n ;
	for(i=1;i<=n;i++)
	{
		cin >> j ;
		if(i!=j)
		k++;
	}
	if(k<=2)
	cout << "YES";
	else
	cout << "NO";
	return 0;
}