#include <iostream>
#include <iomanip>
using namespace std;
 
int main(){
    int H=0,W=0;
    int i,k;

while(1){    



    cin >> H >> W;
	if(H==0&&W==0){
		break;
	}
    
    for(k=0;k<H;k++){//???
    	for(i=0;i<W;i++){//???
    		if((k+i)%2==0){
    			cout << "#";
    		}else{
    			cout << ".";
    		}
    	}
    	cout << endl;
		}
    cout << endl;
    }

return 0;
}