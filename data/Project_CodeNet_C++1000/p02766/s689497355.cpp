#include <iostream>

int main()
{
	long long N;
	int K;

	std::cin >> N >> K;

	// NをK進法にする 
	int ans = -1;
	int gen_num = 0;
	for(int i=0; gen_num<N; i++)
	{
		int degit = 1;
		for(int j=1; j<=i; j++)
		{
			degit *= K;
		}
		gen_num = degit - 1;
//		printf("%d\n", gen_num);
		ans++;
	}
	std::cout << ans << std::endl;
}
