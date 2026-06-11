#include <iostream>
using namespace std;

int main() {
	int n , k=0 , i , l =3e5 ;
	cin >> n ;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i] ;
	}
	for(i=0;i<n;i++)
	{
	   if(a[i]<l)
	   {
	   k++;
	   l=a[i];
	   }
	}
	cout << k ;
	return 0;
}