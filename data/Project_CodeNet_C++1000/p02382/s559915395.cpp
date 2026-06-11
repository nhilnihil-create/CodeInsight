#include <bits/stdc++.h>

using namespace std;

int X[110], Y[110];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << setprecision(6) << fixed;

	int n;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> X[i];
	for(int i=0;i<n;++i)
		cin >> Y[i];
	double d1 = 0, d2 = 0, d3 = 0, dinf = 0;
	for(int i=0;i<n;++i){
		d1+=abs(X[i]-Y[i]);
		d2+=pow(X[i]-Y[i],2);
		d3+=pow((double)(abs(X[i]-Y[i])),3);
		dinf=max(dinf,(double)abs(X[i]-Y[i]));
	}
	cout << d1 << '\n' << sqrt(d2) << '\n' << cbrt(d3) << '\n' << dinf << '\n';	
	
	return 0;

} // br1

