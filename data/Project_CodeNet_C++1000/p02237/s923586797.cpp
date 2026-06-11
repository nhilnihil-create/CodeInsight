#include<iostream>
using namespace std;

int main(){
	int adj[100][100] = {};
	int n;
	cin >> n;
	int a,b,c;
	for (int i=0; i<n;i++){
	cin >> a >> b;
	//adj[num1-1]?????\??????
	
	for (int j=0;j<b;j++){
	cin >> c;
	adj[a-1][c-1] = 1;
	}

	}
	
	for (int i=0;i<n;i++){
	for (int j=0;j<n;j++){
	if (j) cout << " ";
	cout << adj[i][j];
	}
	cout << endl;
	}
	return 0;
}