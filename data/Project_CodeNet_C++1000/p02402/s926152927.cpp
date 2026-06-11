#include <iostream>
using namespace std;



int main(){

	int n,num,max,min;
	long long int sum;

	cin >> n;
	cin >> num;

	max = min = sum = num;


	for (int i = 0; i < n-1; i++){

		cin >> num;
		sum = sum+num;
		if (num >= max){
			max = num;
		}
		if (num <= min){
			min = num;
		}
	}
	cout << min << " " << max << " " << sum << endl;





	return 0;
}