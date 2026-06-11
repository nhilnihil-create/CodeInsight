#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 0, s = 0;


	while (cin >> x >> y >> s)
	{
		int A = 0, B = 0, stemp = 0, stemp2 = 0, stemp3 = 0;

		if (x == 0 && y == 0 && s == 0)
		{
			break;
		}

		for (int i = 1; i < s; i++)
		{
			for (int j = 1; j < s; j++)
			{
				stemp = (i * (x + 100)) / 100 + (j * (x + 100)) / 100;

				if (stemp == s)
				{
					stemp2 = (i * (y + 100)) / 100 + (j * (y + 100)) / 100;
					
					if (stemp2 > stemp3)
					{
						stemp3 = stemp2;
					}
				}
			}
		}

		printf("%d\n", stemp3);
	}
	
	return 0;
}