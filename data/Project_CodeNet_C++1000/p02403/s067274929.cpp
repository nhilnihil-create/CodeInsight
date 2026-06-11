  #include <iostream>
using namespace std;

int main()
{
	int w, h, a, b;
	while ( 1 )
	{
		cin >> h >> w ;
		h , w <= 300 ;
		a = 1 ;
		if ( w == 0 && h == 0 ) break; 
	while (a <= h )
	{
		b = 1 ;
		for (b = 1; b <= w; b++)
		{
			cout << "#" ;
		}
		a += 1;
		cout << endl;
	}
	cout << endl;
}
}