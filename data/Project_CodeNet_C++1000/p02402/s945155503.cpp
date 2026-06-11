#include <iostream>
using namespace std;

int main() {
	int length;
	cin >> length;
	
	long sum=0;
	int max, min;
	
	for(int i=0; i<length; i++){
		int num;
		cin >> num;
		
		sum+=num;
		
		if(i==0){max=num; min=num;}
		else{
		if(num>max){max=num;}
		if(num<min){min=num;}
		}
		
	}
	
	cout << min << " " << max << " " << sum << endl;
	return 0;
}