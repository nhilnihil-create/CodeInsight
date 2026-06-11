#include<bits/stdc++.h>
using namespace std;

int main(){
	// sengen
	int k;
	// nyuryoku
	cin >> k;
	queue<long long> que;
	// keisan
	for(int i=1;i<10;i++) que.push(i);
	for(int i=1;i<=k-1;i++){
		long long now = que.front();
		que.pop();
		for(int j = -1;j<=1;j++){
			long long add = now%10 + j;
			if(add >= 0 && add <= 9){
				que.push(now*10 + add);
			}
		}
	}
	// syutsuryoku
	cout << que.front() << endl;
}