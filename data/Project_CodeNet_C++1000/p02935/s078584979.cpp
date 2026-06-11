#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;

int main(){
	cin >> N;
	vector<double> vec(N);

	rep(i, N)  cin >> vec[i];
	sort(vec.begin(), vec.end());

	double cur = vec[0];
	for(ll i = 1; i < N; i++) {
		cur = (cur + vec[i])/2.0;
	}

	printf("%.20f\n", cur);

}