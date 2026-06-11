#include <iostream>
using namespace std;
int main(void){
	int x,y;
	while(1){
		cin >> x >> y;
		if(!(x+y))break;
		if(x<y)
			cout << x << " " << y << endl;
		else
			cout << y << " " << x << endl;
	}
	return 0;
}