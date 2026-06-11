#include <bits/stdc++.h>
using namespace std;
int main(){
	int H,W,N;
	cin >> H >> W >> N;
	if (N%(max(H,W)) == 0){
		cout << N/max(H,W);
	}else{
		cout << N/(max(H,W)) + 1;
	}
}
	

