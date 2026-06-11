#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N, D,ans=0;

	cin >> N >> D;

	double x, y;

	for (int i = 0; i < N; i++){
		cin >> x >> y;
		double j = sqrt(x*x+y*y);
		if (j <= D)
			ans++;
	}
	
	cout << ans;

}