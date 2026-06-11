#include <iostream>

using namespace std;

int main(){
	long long h;
	cin >> h;
	
	h /= 2;
	long long count = 1;
	
	long long i = 1;
	
	while(h > 0){
		h /= 2;
		count += 2 * i;
		i *= 2;
	}
	
	cout << count << endl;
	
}