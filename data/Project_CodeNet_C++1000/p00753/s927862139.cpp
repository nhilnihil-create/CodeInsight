#include <iostream>

#define for_(i,a,n)    for(int i=a;i<n;i++)
#define rep(i,n)       for_(i,0,n)

using namespace std;

bool np[250000];

int main()
{
	np[0] = np[1] = true;
	for (int i = 2; i * i < 250000; i++)
	{
		if (np[i]) continue;
		for (int j = 2 * i; j < 250000; j += i) np[j] = true;
	}

	int N;
	while(cin>>N,N)
	{
		int c = 0;
		for_(i,N+1,2*N+1) if (!np[i]) c++;
		cout << c << endl;
	}
	return 0;
}