#include<iostream>
using namespace std;
int main()
{
	int sum = 0;
	int a[3][3];
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin >> a[i][j];
		}
	}
	int N;
	cin >> N;
	int b[N];
	for(int i = 0;i < N;i++){
		cin >> b[i];
	}
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			for(int k = 0;k < N;k++){
				if(a[i][j] == b[k]){
					a[i][j] = 0;
					break;
				}
			}
		}
	}
	for(int i = 0;i < 3;i++){
		if(a[i][0] == a[i][1] && a[i][1] == a[i][2]){
			sum += 1;
		}
		if(a[0][i] == a[1][i] && a[1][i] == a[2][i]){
			sum += 1;
		}
	}
	if(a[0][0] == a[1][1] && a[1][1] == a[2][2]){
		sum += 1;
	}
	if(a[0][2] == a[1][1] && a[1][1] == a[2][0]){
		sum += 1;
	}
	if(sum == 0){
		cout << "No";
	}
	else{
		cout << "Yes";
	}
	
	return 0;
}