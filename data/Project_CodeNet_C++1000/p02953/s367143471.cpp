#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> H(N,0);
	for(int i=0;i < N;i++){
		cin >> H[i];
	}
	bool S = true;
	if(N == 1);
	else{
		for(int i = N - 2; 0 <= i; i--){
			if(H[i] - H[i+1] == 1) H[i]--;
			else if(H[i] > H[i+1]){
				S = false;
				break;
			}
		}
	}
	if(S) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}