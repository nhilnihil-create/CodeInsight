#include<bits/stdc++.h>
using namespace std;

main(){
	//          0  1  2  3  4  5  6  7  8  9 10 11 12
	int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	
	for(int i=2; i<=12; ++i){
		days[i] += days[i-1];
	}
	
	char day[][20]={
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday"
	};
	
	while(true){
		// 月, 日
		int m, d;
		cin >> m >> d;
		
		if(m == 0){
			break;
		}
		
		cout << day[(days[m-1]+d-1)%7] <<endl;
	}
}
