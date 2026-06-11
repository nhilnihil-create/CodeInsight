#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a;
	int min, max;
	long sum;
	cin >> a;
	min = a;
	max = a;
	sum += a;
	for(int i = 1; i < n; i++){
		cin >> a;
		if(min > a){
			min = a;
		}else if(max < a){
			max = a;
		}
		sum += a;
	}
	cout << min << " " << max << " " << sum << endl;
}