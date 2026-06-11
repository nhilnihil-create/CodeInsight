#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector <int> vec(3);
	scanf("%d %d %d", &vec[0], &vec[1], &vec[2]);
	sort(vec.begin(), vec.end());
	printf("%d\n", vec[0] + vec[1]);
	return 0;
}