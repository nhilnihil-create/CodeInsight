#include <iostream>
using namespace std;

void swapValue(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;


}

int main(void)
{
	int a1, a2, a3;
	
	cin >> a1 >> a2 >> a3;
	

	if(a1 > a2)
	{
		swapValue(&a1, &a2);
	}


	if(a2 > a3)
	{
		swapValue(&a2, &a3);
	}

	if(a1 > a2)
	{
		swapValue(&a1, &a2);
	}

	cout << a1 << " " << a2 << " " << a3 << endl;


	return 0;

}