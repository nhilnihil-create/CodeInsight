#include <iostream>

using namespace std;

int big = 200;
int small = 195;

int CalcTime(int y,int m,int d){
	int sum = 0;
	//??´
	for (int i = 1; i < y; i++){
		if (i%3 == 0){
			sum += 200;
		}
		else{
			sum += 195;
		}
	}
	//???
	if (y%3 == 0){
		sum += 20 * (m - 1);
	}
	else{
		for (int i = 1; i < m; i++){
			if (i%2 == 0){
				sum += 19;
			}
			else{
				sum += 20;
			}
		}
	}
	//??\
	sum += d;
	return sum;
}

int main(){
	int n;
	int y, m, d;
	int millennium = CalcTime(1000,1,1);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> y >> m >> d;
		cout << millennium - CalcTime(y,m,d) << endl;
	}

	return 0;
}