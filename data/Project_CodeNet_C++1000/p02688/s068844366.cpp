#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<bool> a(N, false);
	for (int i = 0; i < K; i++)
	{
		int d, b;
		cin >> d;
		for(int j=0; j<d; j++)
		{
			cin >> b;
			a[b - 1] = true;
		}
	}
	
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		if(!a[i]) ans++;
	}
	
	cout << ans << endl;
}
