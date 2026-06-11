#include<iostream>
#include<vector>
using namespace std;

int MaxProfit(vector<int> A){
	int start_number = 0;
	int profit = A[1] - A[0];
	while(1){
		int i;
		for(i = start_number + 1; i < A.size(); i++){
			if(A[i] - A[start_number] < 0){
				start_number = i;
				break;
			}
			if(A[i] - A[start_number] > profit){
				profit = A[i] - A[start_number];
			}
		}
		if(i >= A.size() - 1) break;
	}
	return profit;
}

int main(){
	int n;
	cin >> n;
	vector<int> A;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}
	cout << MaxProfit(A) << endl;
	return 0;
}