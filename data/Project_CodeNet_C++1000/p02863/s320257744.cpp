#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N, T;
	int A[3001];
	int B[3001];
	cin >> N >> T;
	for(int i = 1; i <= N; i++){
		cin >> A[i] >> B[i];
	}
	
	const int N_MAX = 3001;
	const int T_MAX = 3001;
	static ll DP[N_MAX][T_MAX][2]; // 3次元目は、「最後に食べる料理」を既に予約したか否か
	for(int i = 0; i < N_MAX; i++){
		for(int j =0; j < T_MAX; j++){
			DP[i][j][0] = 0;
			DP[i][j][1] = 0;
		}
	}
	
	for(int n = 1; n <= N; n++){
		for(int t = 0; t < T; t++){
			DP[n][t][0] = DP[n-1][t][0];
			if(t -A[n] >= 0){
				DP[n][t][0] = max(DP[n][t][0], DP[n-1][t-A[n]][0]+B[n]);
			}
			
			DP[n][t][1] = max(DP[n-1][t][0]+B[n], DP[n-1][t][1]);
			if(t -A[n] >= 0){
				DP[n][t][1] = max(DP[n][t][1], DP[n-1][t-A[n]][1]+B[n]);
			}
		}
	}
	cout << DP[N][T-1][1] << endl;
	
	return 0;
}