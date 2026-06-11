#include <iostream>
using namespace std;
 
int main()
{
	int h, w, ww;

	cin >> h >> w;
 
	while((h != 0) && (w != 0)) {
		while(h--) {
			ww = w;
			while(ww--)
				cout << '#';
			cout << endl;
		}
		cout << endl;
		cin >> h >> w;
	}
	return 0;
}