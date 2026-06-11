#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, M;

long long WC[100005];
bool AC[100005];

int main(){
	cin >> N >> M;
	long long ac = 0;
	long long wc = 0;
	rep(i, M) {
		long long num;
		string res;
		cin >> num >> res;
		if(res == "WA") {
			if(!AC[num]) {
				WC[num]++;
			}
		} else {
			if(!AC[num]) {
				ac++;
				AC[num] = true;
			}
		}
	}
	rep(i, N+2) {
		if(AC[i]) wc += WC[i];
	}


	cout << ac << " " << wc << endl;

}