#include <iostream>
using namespace std;


int main(){
	int i,n;
	cin >> n;
	for(i=1;i<=n;i++){
		if(i%3 == 0) cout << " " << i;	//3????????°
		else if(i/10000 == 3) cout << " " << i;
		else if((i%10000) / 1000 == 3) cout << " " << i;
		else if((i%1000) / 100 == 3 ) cout << " " << i;
		else if((i%100) / 10 == 3) cout << " " << i;
		else if((i%10) == 3) cout << " " << i;
	}
	cout << endl;
	return 0;
}