#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
char S[100100];

int main()
{
	scanf ("%d %d", &N, &K);
	scanf ("%s", S);

	int h = 0;
	for (int i = 0; S[i]; i++){
		if (S[i] == 'L'){
			if (i == 0 || S[i - 1] == 'R');
			else h++;
		}
		else{
			if (S[i + 1] == 'R') h++;
		}
	}

	h += 2 * K;
	if (h >= N) h = N - 1;
	printf ("%d\n", h);

	return 0;
}