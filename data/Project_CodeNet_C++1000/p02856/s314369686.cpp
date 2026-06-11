#include<iostream>
using namespace std;
long long sum;
long long cnt;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		int x;
		long long y;
		cin >> x >> y;
		sum += x * y;
		cnt += y;
	}
	if(sum >= 10){
		sum -= 1;
		sum /= 9;
		sum += (cnt - 1); 
	}
	else{
		sum = cnt - 1;
	}
	cout << sum;
	return 0;
}