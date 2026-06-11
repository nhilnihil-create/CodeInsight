#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, K, Q;
ll score[100005];
ll A[100005];

int main(){
	cin >> N >> K >> Q;

	rep(i, N) {
		score[i] = -Q + K;
	}

	rep(i, Q) {
		ll a;
		cin >> a;
		a--;
		score[a]++;
	}

	rep(i, N) {
		if(score[i] > 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

}