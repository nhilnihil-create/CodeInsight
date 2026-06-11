#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	double sum = 0;
	cin >> N;
	rep(i, N) {
		double tmp;
		cin >> tmp;
		sum += 1.0/tmp;
	}
	printf("%.10f\n", 1/ sum);

}
