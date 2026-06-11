#include<iostream>

using namespace std;

int main() {
	
	int x, y, z, count = 0;
	
	while( cin >> x >> y >> z ) {
		
	for(int i=x;x<=y;x++)
	if(z % x == 0)
	count++;
	
	cout << count << "\n";
	count = 0;
	}
		
	return 0;
}
