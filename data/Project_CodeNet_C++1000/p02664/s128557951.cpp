#include <stdio.h>

char S[200200];

int main()
{
	scanf ("%s", S);
	for (int i = 0; S[i]; i++) if (S[i] == '?') S[i] = 'D';
	puts(S);

	return 0;
}
