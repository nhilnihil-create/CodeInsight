#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int main(void)
{
	int i,lr,rl, N, K,maxnumber=0;
	char s[100001];
	cin >> N;
	cin >> K;
	for (i = 0; i < N; i++)
		cin >> s[i];
	s[i] = '\0';
	lr = rl = 0;
	for (i = 0; i < N; i++)
	{
		if (s[i] == 'L')
		{
			if (s[i - 1] == 'L')
				maxnumber++;
			if (s[i + 1] == 'R')
				lr++;
		}
		else
		{
			if (s[i + 1] == 'R')
				maxnumber++;
			if (s[i + 1] == 'L')
				rl++;
		}
	}
	maxnumber += 2 * (min(rl, lr) > K ? K:min(rl,lr));
	if (min(rl, lr) < K)
		maxnumber += min(K - min(rl, lr), abs(rl - lr));
	cout << maxnumber << endl;
}