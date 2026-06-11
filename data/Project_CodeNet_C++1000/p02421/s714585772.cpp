#include<iostream>
#include<string>
using namespace std;

int main() {
	int n,taro,hanako;
	cin >> n;
	string a[n][2];
	for(int i = 0; i < n; i++){
		cin >> a[i][0];
		cin >> a[i][1];
	}
	for(int i = 0; i < n; i++){
		if(a[i][0] > a[i][1]){
			taro += 3;
		}else if(a[i][0] < a[i][1]){
			hanako += 3;
		}else{
			taro++;
			hanako++;
		}
	}
	cout << taro << " " << hanako << endl;
	return 0;
}
