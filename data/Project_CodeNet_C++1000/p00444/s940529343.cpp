#include <iostream>
 
using namespace std;
 
int main()
{
	int change,money;

	while(1){
	cin>>money;
	if(money<1||money>1000){
		break;
	}else{
		int  coin,coin1,coin2,coin3,coin4,coin5,coin6;

		change=1000-money;

		coin1=change/500;
		coin2=change%500/100;
		coin3=change%500%100/50;
		coin4=change%500%100%50/10;
		coin5=change%500%100%50%10/5;
		coin6=change%500%100%50%10%5/1;

		coin=coin1+coin2+coin3+coin4+coin5+coin6;
		cout<<coin<<"\n";
	
		}
	}



    return 0;
}