#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<vector<int>> m(3, vector<int>(3));
	vector<vector<bool>> marca(3,vector<bool>(3,0));

	for (int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			scanf("%d", &m[i][j]);

	int n, ans = 0;
	scanf("%d", &n);

	while(n--){
		
		int b;
		scanf("%d", &b);

		for (int i=0;i<3;i++)
			for (int j=0; j<3; j++)
				if (m[i][j]==b)	marca[i][j]=1;
	}

	for (int i=0;i<3;i++){
	
			if (marca[i][0]+marca[i][1]+marca[i][2] == 3 | 
				marca[0][i]+marca[1][i]+marca[2][i] == 3 |
				marca[0][0]+marca[1][1]+marca[2][2] == 3 |
				marca[0][2]+marca[1][1]+marca[2][0] == 3){

					ans = 1;
					break;
			}
	}
	
	printf((ans) ? "Yes\n" : "No\n");
	return 0;
}
