#include<iostream>
using namespace std;

#define MAX 100
int main(){
	int n, m, l;  //a:(n,m),b:(m,l)
	
	cin >> n >> m >> l;
	
	//配列の定義	
	int a[MAX][MAX];
	int b[MAX][MAX];
	long c[MAX][MAX];
	
	//データの読み込み
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int j = 0; j < m; j++){
		for(int k = 0; k < l; k++){
			cin >> b[j][k];
		}
	}
	
	//行列の積を計算
	for(int i = 0; i < n; i++){
		for(int j = 0; j < l; j++){
			c[i][j] = 0;
			for(int k = 0; k < m; k++){
				c[i][j] += a[i][k]*b[k][j];
			}
			cout << c[i][j];
			if(j == l-1)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}