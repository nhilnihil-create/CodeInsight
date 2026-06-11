#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
 
 
int main()
{
  	int N;
	cin >> N;
	vector <float> v(N);
	float answer;
	rep (i,N){
		cin >> v.at(i);
	}
	sort(v.begin(), v.end());
	answer = v[0];
	for (int i=1;i<N;i++){
		answer = (answer + v[i])/2;
	}
	cout << std::setprecision(10) << answer << endl;
	return 0;
}