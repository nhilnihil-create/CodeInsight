#include <bits/stdc++.h>
using namespace std;
int n , m , a , b , grid[2000][2000];
int main(){
	cin >> n >> m >> a >> b;
	for(int i = 1 ; i <= b ; i++){
		for(int j = a + 1 ; j <= m ; j++){
			grid[i][j] = 1;
		}
	}
	for(int i = b + 1 ; i <= n ; i++){
		for(int j = 1 ; j <= a ; j++){
			grid[i][j] = 1;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
}