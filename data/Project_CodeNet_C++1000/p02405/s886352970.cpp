#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main(){
	int H;
	int W;
	int j;
	int i;
	for(H=1,W=1;;){
		cin>>H>>W;
		if(H==0&&W==0)break;
		for(i=0; i<H; i++){
			for(j=0; j<W; j++){
				if(i%2 == 0 && j%2 == 0)cout<<"#";
				else if(i%2 == 1 && j%2 == 1)cout<<"#";
				else cout<<".";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}