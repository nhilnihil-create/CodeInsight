#include<iostream>

using namespace std;

int n, s;
int c = 0;
int i = 0;
int j = 0;
int q = 0;
int sum = 0;
int date[15] = { 0 };



int sub(int start,int n,int x){
	if (x == n){
		for (int i = 0; i < n; i++){
			
				sum += date[i];
		}
		if (sum == s){
			q++;
		}
		sum = 0;
		return 0;
	}

	for (int i = start; i < 10;i++){

		date[x] = i;

		sub(i + 1, n, x + 1);
	
	}


}



int main(){

	n = 0;
	while (true){
		cin >> n >> s;
		if (n == 0 && s == 0)break;
		sub(0, n, 0);


		cout << q << endl;
		q = 0;
	}
}