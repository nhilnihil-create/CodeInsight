#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

double x[10];
double y[10];

int main(){
	long long N;
	cin >> N;

	rep(i, N) {
		cin >> x[i];
		cin >> y[i];
	}

	vector<long long>vec;
	rep(i, N) {
		vec.push_back(i);
	}


	double sum = 0;
	double cnt = 0;
	do {
		cnt++;

		rep(i, N-1) {
			long long idx = vec[i];
			long long next = vec[i+1];
			sum += sqrt((x[idx] - x[next]) *  (x[idx] - x[next]) + (y[idx] - y[next]) *  (y[idx] - y[next]));
		}
	} while (std::next_permutation(vec.begin(), vec.end()));

	printf("%.10f\n", sum/cnt);
}
