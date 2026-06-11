#include <stdio.h>

int main()
{
	char S[10]; scanf ("%s", S);
	puts(S[2] == S[3] && S[4] == S[5] ? "Yes" : "No");
	return 0;
}