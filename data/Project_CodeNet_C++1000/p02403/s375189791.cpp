#include <iostream>
using namespace std;

int main() {
	int h, w;
	while(h+w)
	{
		cin >> h >> w;
		for(int i =0; i < h; i++){
			for(int j = 0; j < w; j++){
				cout << "#";
			}
			cout << endl;
		}
		if(h+w)cout << endl;
	}
	// your code goes here
	return 0;
}