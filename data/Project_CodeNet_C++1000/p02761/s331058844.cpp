#include<bits/stdc++.h>
using namespace std;


long long N, M;
long long S[10];
char C[10];

int main(){
	cin >> N >> M;

	for(long long i = 0; i < M; i++) {
		cin >> S[i] >> C[i];
		S[i]--;
	}

	for(int i = 0; i < pow(10, N); i++) {
		string s = to_string(i);
		//cout << s << endl;
		if(s.size() != N) 
			continue;

		bool ok= true;
		for(long long j = 0; j < M; j++) {
			if(s[S[j]] != C[j]) {
				ok = false;
			}
		}
		if(ok) {
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
