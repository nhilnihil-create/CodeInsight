#include<iostream>
using namespace std;
int main()
{
	int n, c = 0;
	cin>>n;
	for(int x = 1; x <= n; x++){
		int z;
		cin>>z;
		c+=((x % 2) && (z % 2));
	}
	cout<<c<<endl;
	return 0;
}






