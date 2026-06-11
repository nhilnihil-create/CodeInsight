#include <iostream>
using namespace std;

main(){
	int y,m,d,sum,n;
	cin >> n;
	while(n--){
		sum = 0;
		cin >> y >> m >> d;
		while(y!=1000 || m!=1 || d!=1){
			d ++;
			if(!(y%3)||m%2){
				if(d==21){d = 1;m ++;}
			}else{
				if(d==20){d = 1;m ++;}
			}
			if(m==11){m = 1;y ++;}
			sum ++;
		}
		cout << sum << endl;
	}
	
	return 0;
}