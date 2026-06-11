#include <iostream>
using namespace std;

int main(void)
{
	int h, w;
	int i, j;
	
	while (1){
		cin >> h >> w;
		
		if (h == 0 && w == 0){
			break;
		}
		
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				cout << "#";
			}
			cout << endl;
		}
		
		cout << "\n";
	}
	
	return (0);
}