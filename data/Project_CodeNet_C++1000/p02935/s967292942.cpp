#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)



int main() {
	int N;
	double ans=0;
	cin >> N;
	vector<double> vec(N);
	rep(i, N) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	rep(i, N) {
		int p = N - i;
		if (i==0 || i==1)
		{
			p = N - 1;
			
		}
		ans += vec.at(i) * pow(0.5,p);
	}
	cout << ans << endl;
}