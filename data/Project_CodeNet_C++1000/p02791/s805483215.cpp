#include<iostream>

using namespace std;

int a[200000];

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> a[i];
	
	int min = a[0],ans=1;
	
		for (int j = 1; j < N; j++)
			if (min > a[j]) {
				++ans;
				min = a[j];
			}
		cout << ans;
}
