#include<iostream>
using namespace std;
int main()
{
	int n, squares[105], ans=0; cin>>n;

	for(int i=1; i<= n;++i)
		{
			cin>>squares[i];

		}
	for(int i=1; i<= n;++i)
	{
		if(squares[i]%2 !=0 && i %2 !=0) ans++;
	}
	cout<<ans<<endl;





}