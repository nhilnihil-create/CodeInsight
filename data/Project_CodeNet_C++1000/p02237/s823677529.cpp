#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;

	int g[n][n] = {};
	for(int i=0;i<n;i++){
		int u, nume;
		cin >> u >> nume;

		int v;
		for(int j=0;j<nume;j++){
			cin >> v;
			g[u-1][v-1]= 1;
		}

	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << g[i][j];
			if(j != n-1) cout << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
