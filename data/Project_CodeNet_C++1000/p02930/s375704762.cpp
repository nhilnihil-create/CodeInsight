#include<bits/stdc++.h>
using namespace std;

long long N;
long long ans[505];


int check(long long p1, long long p2){
	int i = 1;
	while(p1>0 || p2>0){
		if((p1&1) != (p2&1)){
			return i;
		}
		p1 = (p1>>1);
		p2 = (p2>>1);
		i++;
	}
	exit(1);
}


int main(){
	cin >> N;

	for(long long i = 0; i < N; i++){
		for(long long j = i + 1; j < N; j++){
			cout << check(i, j);
			if(j != N-1){
				cout << " ";
			}else{
				cout << endl;
			}
		}
	}
}