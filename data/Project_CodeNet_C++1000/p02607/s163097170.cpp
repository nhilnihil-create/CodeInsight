#include <iostream>
using namespace std;
int main()
{
	int x = 0 , l=1 ;
	int z ;
	cin >> z;
	int N[z];
	for (int i = 0; i < z; i++)
	{
		cin >> N[i];
		if (l % 2 != 0 && N[i] % 2 != 0)
		{
			x++;
			
		}
l++;
	}
	cout << x << endl;
return 0 ; 

}
