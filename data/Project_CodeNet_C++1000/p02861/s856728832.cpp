#include <bits/stdc++.h>
using namespace std;


void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}


int main(){
	int N;
	cin >> N;
	double x[N], y[N];
	for(int i=0;i<N;i++){
		cin >> x[i] >> y[i];
		// printf("%.1f, %.1f\n",x[i], y[i]);
	}
	double D[N][N] ={0};
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			double X = x[i] - x[j];
			double Y = y[i] - y[j];
			double d = X * X + Y * Y; 
			D[i][j] = sqrt(d);
			// printf("%.9f, %.5f\n", D[i][j], d);
		}
	}
	double cnt = 0;
	vector<int> nums(N);
	iota(nums.begin(), nums.end(), 0);
	double ans = 0;
	do{
		for(int i=0;i<N-1;i++){
			ans += D[nums[i]][nums[i+1]];
		}
		// printVector(nums);
		// printf("%.9f\n", ans);
		cnt += 1;
	} while(next_permutation(nums.begin(), nums.end()));
	ans /= cnt;
	printf("%.9f\n", ans);
	// printf("%.9f\n", cnt);
}