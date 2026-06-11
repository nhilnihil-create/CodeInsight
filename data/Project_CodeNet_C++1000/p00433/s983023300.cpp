#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int a, b, c, d, x, y, z, w, s, t;
	
	while(cin >> a >> b >> c >> d){
		s = a+b+c+d;
		cin >> a >> b >> c >> d;
		t = a+b+c+d;
		
		cout << ((s > t)? s : t) << endl;
	}
	
	return 0;
}