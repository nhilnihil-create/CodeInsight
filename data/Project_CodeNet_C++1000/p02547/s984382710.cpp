#include <string>
#include <iostream>

using namespace std;

int main(){
	int tt, d1, d2, cs = 0;
	cin >> tt;
	while(tt--){
		cin >> d1 >> d2;
		if (d1 == d2)
			cs ++;
		else if (cs < 3)
			cs = 0;
	}
	if (cs >= 3){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}
		
