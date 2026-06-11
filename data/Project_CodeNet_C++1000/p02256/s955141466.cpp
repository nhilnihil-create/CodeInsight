#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int x,y;
	cin >> x>>y;
	if(x<y) swap(x,y);
	while(y!=0){
		int r=x%y;
		x=y;
		y=r;
	}
	cout <<x<<endl;
	return 0;
}