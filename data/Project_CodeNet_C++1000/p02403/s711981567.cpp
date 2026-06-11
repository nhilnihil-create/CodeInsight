#include<iostream>
using namespace std;
int main(void)
{
	int H,W,h,w;

	while(1){
		cin >> H >> W;
		if(H==0 && W==0)break;

		for(h=1 ; h<=H ; h++){
			for(w=1 ; w<=W ; w++){
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}