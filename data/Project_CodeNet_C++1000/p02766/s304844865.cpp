#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	long long K;
	cin >> N >> K;
	long long tmp = K;
	long long cnt = 1;
	while(N >= tmp){
		cnt++;
		tmp *= K;
	}
	cout << cnt << endl;
}
