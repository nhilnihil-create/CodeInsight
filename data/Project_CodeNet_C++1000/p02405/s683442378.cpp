#include <iostream>

#define rep(i,n)for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int h,w;
	while(cin >> h >> w)
	{
		if(h == 0 && w == 0) break;

		rep(i,h)
		{
			rep(j,w)
			{
				if(i%2 == 0)
				{
					if(j%2 == 0)
					{
						cout << "#";
					}
					else
					{
						cout << ".";
					}
				}
				else
				{
					if(j%2 == 0)
					{
						cout << ".";
					}
					else
					{
						cout << "#";
					}
				}
			}
			cout << endl;
		}
		cout  << endl;
	}
	return 0;
}