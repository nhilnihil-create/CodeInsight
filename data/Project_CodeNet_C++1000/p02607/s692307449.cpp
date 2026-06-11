#include <iostream>
using namespace std;
int main()
{
	int n,vl=0;
	cin>>n;
	int *arr=new int [n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	for (int i=0,h=1;i<n;i++,h++)
	{
		if (arr[i]%2!=0 && h%2!=0)
		vl++;
	}
	cout<<vl;
}