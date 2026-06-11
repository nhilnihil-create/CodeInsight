#include <iostream>
using namespace std;

int main() {
	int h, w;
	while(1){
		cin >> h >> w;
		if(h==0 && w==0) break;
		for(int i=1; i<=h; i++){
			for(int x=1; x<=w; x++){
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}