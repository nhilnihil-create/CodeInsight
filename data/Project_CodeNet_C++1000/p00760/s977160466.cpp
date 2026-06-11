#include <iostream>

using namespace std;

int main(){
	int n;
	int y,m,d;
	int sandewareru;
	int warenai;
	int months;
	int years;
	cin>>n;

	for(int i=0;i<n;i++){
		int days=0;
		cin>>y>>m>>d;

		years=y-1;
		months=m-1;
		

		sandewareru=years/3;//3??§???????????´?????°
		warenai=years-sandewareru;//3??§??????????????´?????°

		days+=sandewareru*200;
	

		days+=warenai*195;

	
		
		
		if(y%3==0){//???????????§?????´
			days+=months*20;
		}else{
			if(months%2==0){
				days+=(months/2)*39;
			}else{
				days+=((months/2)*39+20);
			}
		}
		days+=d;

		
		

	cout<<196471-days<<endl;
	}

	
	return 0;


}