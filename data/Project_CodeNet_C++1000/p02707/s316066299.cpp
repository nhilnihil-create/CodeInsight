#include<bits/stdc++.h>
using namespace std;

long long N;
map<long long, long long> ans;

int main(){
	cin >> N;
	for(long long i = 0; i < N-1; i++) {
		long long tmp;
		cin >> tmp;
		tmp--;
		ans[tmp]++;
	}

	for(long long i = 0; i < N; i++) {
		cout << ans[i] << endl;

	}

}