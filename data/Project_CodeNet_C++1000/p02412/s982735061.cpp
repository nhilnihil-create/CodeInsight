#include<iostream>
using namespace std;
int main(){
	int n,n2,n3,count=0,count2,number,number2,ans[100]={0};
	while(1){
		cin>>number>>number2;
		if(number==0&&number2==0){break;}
		for(n=1;n<=number;n++){
			for(n2=n+1;n2<=number;n2++){
				for(n3=n2+1;n3<=number;n3++){
					if((n+n2+n3)==number2){ans[count]++;}
				}
			}
		}
		count++;	
	}
	for(count2=0;count2<count;count2++){
		cout<<ans[count2]<<endl;
	}
	return 0;
}