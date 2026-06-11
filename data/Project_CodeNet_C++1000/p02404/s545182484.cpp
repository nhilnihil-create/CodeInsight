#include <iostream>
using namespace std;

int main(){
	int H,W;
	int i,j;

	while(1){
		
		cin >> H >> W;
		if(H==0 && W==0) break;

	    for(i=1;i<=H;i++){
			if(i==1 || i==H){
				for(j=1;j<=W;j++){
					cout << "#";
				}
			} else {
				cout << "#";
				for(j=2;j<=W-1;j++){
					cout <<".";
				}
				cout << "#";
			}

			cout << "\n";
		
		}

		cout << endl;

	}

	return 0;

}