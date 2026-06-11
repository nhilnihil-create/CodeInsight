#include <iostream>
#include <cmath>
#define INF 100000000
using namespace std;

int main(){
	int d[10][10];
	int n;
	while(cin >> n,n){
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 10;j++){
				d[i][j] = INF;
			}
			d[i][i] = 0;
		}
		int num = 0;
		for(int i = 0;i < n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			num = max(num,max(a,b));
			d[a][b] = c;
			d[b][a] = c;
		}
		num++;
		for(int k = 0;k < num;k++){
			for(int i = 0;i < num;i++){
				for(int j = 0;j < num;j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
		int res = INF,minnum = -1;
		for(int i = 0;i < num;i++){
			int sum = 0;
			for(int j = 0;j < num;j++){
				sum += d[i][j];
			}
			if(sum < res){
				res = sum;
				minnum = i;
			}
		}
		cout << minnum << " " << res << endl;
	}
	return 0;
}