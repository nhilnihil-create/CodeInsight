#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma warning(disable:4996)
int main()
{
	char Work[256];

	int Num[2];
	int Divide;
	int nCnt2,nCnt = 0, Result, Keta = 1;

	while (gets(Work))
	{
		for (nCnt = 0; Work[nCnt] != '\0'; nCnt++)
		{
			if (Work[nCnt] == ' ')
			{
				char Work2[256];
				char Work3[256];

				strcpy(Work2, &Work[nCnt]);

				Work[nCnt] = '\0';

				strcpy(Work3, Work);

				Num[0] = atoi(Work3);
				Num[1] = atoi(Work2);
				break;
			}
		}

		Result = Num[0] + Num[1];

		Keta = 1;
		for (nCnt = 0; ;nCnt++)
		{
			Result = Result / 10.0f;

			if (Result > 0)
				Keta++;
			else
				break;
		}

		printf("%d\n", Keta);
	}
	
	return 0;
}