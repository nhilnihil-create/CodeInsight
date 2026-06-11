#include<bits/stdc++.h>
using namespace std;

bool is_integer(double x){
	return floor(x) == x;
}


int main(){
	int n,d;
	cin >> n >> d;
	vector<vector<int>> x(n,vector<int>(d));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < d; j++){
			cin >> x[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			int dis = 0;
			for (int k = 0; k < d; k++)
				dis += pow((x[i][k]-x[j][k]),2);
			double dis2 = sqrt(dis);
			if (is_integer(dis2))
				ans += 1;
		}
	}
	
	cout << ans << endl;
	return 0;
}