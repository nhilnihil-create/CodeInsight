#include <iostream>

using namespace std;
int n, year, month, day;

main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> year >> month >> day;
		if (year % 3 != 0){
			cout << 196471-(((year - 1) / 3) * (390 + 200) + ((year - 1) % 3) * (195) + ((month - 1) / 2) * (19) + ((month - 1) % 2 + (month - 1) / 2) * (20) + day) << endl;
		}else{
			cout << 196471-(((year - 1) / 3) * (390 + 200) + ((year - 1) % 3) * (195) + (month - 1) * (20) +  day) << endl;
		}
		
	}
}
