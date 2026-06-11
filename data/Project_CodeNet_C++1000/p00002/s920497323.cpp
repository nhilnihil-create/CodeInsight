#include <iostream>
using namespace std;

int main(){
	int x,y;
	int tmp;
	int count = 0;
	while(cin >> x >> y){
		tmp = x + y;
		count = 0;
		while(tmp != 0){
			tmp /= 10;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}		