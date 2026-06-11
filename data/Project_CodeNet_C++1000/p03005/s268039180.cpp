#include "bits/stdc++.h"
using namespace std;
// 10:43
int main(){
	std::ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	if(N%K==0){
		cout << 0;
	}else{
		cout << N-K;
	}
}

 
