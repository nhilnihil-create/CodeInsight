#include<iostream>
using namespace std;
int main(void)
{
	int H,W,h,w;

	while(1){
		cin >> H >> W;
		
		if(H==0 && W==0)break;
		
		for(w=1 ; w<=W ; w++){
			cout << "#";
		}
		
		cout << endl;
		
		for(h=3 ; h<=H ; h++){
			cout << "#";
			for(w=3 ; w<=W ; w++){
				cout << ".";
			}
			cout << "#\n";
		}
		
		for(w=1 ; w<=W ; w++){
			cout << "#";
		}
		cout << endl << endl;
	}
	
	return 0;
}