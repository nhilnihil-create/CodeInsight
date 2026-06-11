#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	int h=-1, w=-1;


	char tmp='.';
	cin >> h >> w;
	while (h != 0 && w != 0){
		
		for (int i = 1; i <= h; i++){
			if (i % 2 != 0){ tmp = '#'; }
			else{ tmp = '.'; }
			for (int s = 0; s < w; s++){
				cout << tmp;
				if (tmp == '#'){ tmp = '.'; }
				else{ tmp = '#'; }
				
			}
			cout << endl;
		}
		cout << endl;
		cin >> h >> w;	
	}

	return 0;
}