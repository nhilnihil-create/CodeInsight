#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; 
	cin >> N;
	int nums[N][2];
	for(int i = 0; i < N; ++i){
		cin >> nums[i][0] >> nums[i][1];
	}
	for(int i = 0; i < N-2; ++i){
		if (nums[i][0] == nums[i][1] && nums[i+1][0] == nums[i+1][1] && nums[i+2][0] == nums[i+2][1]){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}
