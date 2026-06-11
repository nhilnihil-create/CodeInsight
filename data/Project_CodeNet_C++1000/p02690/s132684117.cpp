#include<cstdio>
 
int main()
{
	int X;
	scanf("%d", &X);
    long pow5[240];
    for (int i = 0; i < 120; i++)
    {
        long x = i;
        pow5[120+i] = x * x * x * x * x;
        pow5[120-i] = -pow5[120+i];
    }
	for (int A = 0; A < 120; ++A) {
      	for (int B = -120; B < A; ++B) {
			if (pow5[120+A] - pow5[120+B] == X)
			{
				printf("%d %d", A, B);
				return 0;
            }
		}
    }
}
