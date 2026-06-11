#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int min =2*10*10*10*10*10+1;
	int count = 0;
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		if(p <= min){
			min = p;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}