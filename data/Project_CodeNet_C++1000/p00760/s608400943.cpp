#include <iostream>
using namespace std;

int n;
main(){
	int y,m,d,sum,n,k;
	int pre = 196470;
	cin >> n;
	while(n--){
		sum = 0;
		cin >> y >> m >> d;
		sum += ((y-1) * 200) - ((y-1)-(y-1)/3)*5;
		sum += 20 * (m-1);
		if(y % 3) sum -= ((m-1)/2);
		sum += d;
		cout << pre - sum + 1 << endl;
	}
	
	return 0;
}