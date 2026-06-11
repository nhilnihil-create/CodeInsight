#include <bits/stdc++.h>
using namespace std;

int main(){
	queue<long long> que;
	long long A, B;
	cin >> A >> B;
	long long ans = 0;
	long long tmp = A;
	que.push(1);
	for(long long i=2;i*i<=A;i++){
		if(tmp % i == 0){
			que.push(i);
			while(tmp % i == 0)tmp /= i;
		}
	}
	if(tmp > 1)que.push(tmp);
	while(!que.empty()){
		long long j = que.front();
		que.pop();
		if(B % j == 0)ans++;
	}
	cout << ans << endl;
}