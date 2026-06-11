#include<iostream>

using namespace std;

int main()
{
	int N,ans;

	cin >> N;
	
	int j = 1;

	while (1000 * j < N) {
		j++;
	}
	
	ans=(1000 * j) - N;

	cout << ans;
}