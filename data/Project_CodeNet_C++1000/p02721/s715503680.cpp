#include<bits/stdc++.h>
using namespace std;

long long N, K, C;
string S;
long long head[200005];
long long tail[200005];

int main(){
	cin >> N >> K >> C >> S;

	long long last = LONG_MIN;
	long long idx = 1;
	for(long long i = 0; i < N; i++) {
		if(S[i] == 'o' && i > last + C) {
			last = i;
			head[i] = idx;
			idx++;
		}
	}

	//if(idx > K + 1) {
	//	return 0;
	//}

	last = LONG_MAX;
	idx = K;
	for(long long i = N-1; i >= 0; i--) {
		if(S[i] == 'o' && last > i + C) {
			last = i;
			tail[i] = idx;
			idx--;
		}
	}


	//for(long long i = 0; i < N; i++) {
	//	cout << "head[" << i << "] = " << head[i] << endl;
	//}

	//for(long long i = 0; i < N; i++) {
	//	cout << "tail[" << i << "] = " << tail[i] << endl;
	//}

	for(long long i = 0; i < N; i++) {
		if(head[i] != 0 && head[i] == tail[i]) {
			cout << i + 1 << endl;
		}
	}



}
