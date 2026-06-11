#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;

    cin >> n;
	for(int i = 1; i<= n; i++)
	{
		if(i%3 == 0)
        {
			printf(" %d",i);
		}
        else
        {
			x = i;
			do
            {
				if(x%10 == 3)
                {
					printf(" %d",i);
					break;
				}
				x /=10;
			}
            while(x);
		}
	}
	printf("\n");
    return 0;
}

