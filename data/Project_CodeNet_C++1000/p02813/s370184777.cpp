#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
vector<long long> P;
vector<long long> Q;
int main(){
	cin >> N;
	rep(i, N) {
		long long tmp;
		cin >> tmp;
		P.push_back(tmp);
	}
	rep(i, N) {
		long long tmp;
		cin >> tmp;
		Q.push_back(tmp);
	}


	vector<long long> arr;
	rep(i, N) {
		arr.push_back(i+1);
	}

	long long idx = 0;
	long long pidx = -1;
	long long qidx = -1;
	do {
		bool pok = true;
		rep(i, N) {
			if(arr[i] != P[i]) {
				pok = false;
			}
		}
		if(pidx == -1 && pok) {
			pidx = idx;
		}


		bool qok = true;
		rep(i, N) {
			if(arr[i] != Q[i]) {
				qok = false;
			}
		}
		if(qidx == -1 && qok) {
			qidx = idx;
		}
		idx++;
	} while (std::next_permutation(arr.begin(), arr.end()));

	cout << abs(pidx - qidx) << endl;

}

