#include <iostream>
using namespace std;
int main()
{
	int count = 0 , k=1 ;
	int z ;
	cin >> z;
	int N[z];
	for (int i = 0; i < z; i++)
	{
		cin >> N[i];
		if (k% 2 != 0 && N[i] % 2 != 0)
		{
			count++;
			
		}
		k++;
	}
	cout << count << endl;
	return 0;
}