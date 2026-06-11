#include <iostream>

int main(void)
{
	using namespace std;
	
	int H,W;
	while(1){
		cin >> H;
		cin >> W;

		if((H==0) && (W==0))	break;
		else{
			for(int hy=0; hy<H; ++hy){
				for(int wx=0; wx<W; ++wx){
					cout << "#";
				}
				cout << endl;
			}
		}
		cout << endl;
	}


	return 0;

}