#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
vector<pair<long long, long long> > vec;

int main(){
	cin >> N;
	rep(i, N) {
		long long a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}

	sort(vec.begin(), vec.end());


	rep(i, N) {
		cout << vec[i].second + 1;
		if(i != N-1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}