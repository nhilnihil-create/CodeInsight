#include <bits/stdc++.h>

using namespace std;

int main(void){
	int num, all;
	cin >> num;
	all = (999 - 999 / 3) * (20 * 5 + 19 * 5) + 999 / 3 * 20 * 10;

	for(int i = 0; i < num; i++){
		int y, m, d;
		int millenium;
		cin >> y >> m >> d;
		
		millenium = ((y-1) - (y-1) / 3) * (20 * 5 + 19 * 5) + (y-1) / 3 * 20 * 10;
		if(y % 3 != 0){
			millenium += ((m - 1) / 2) * 19 + ((m - 1) - ((m - 1) / 2)) * 20 + d;
		}else{
			millenium += (m - 1) * 20 + d;
		}
		cout << all -  millenium + 1 << endl;	
	}
	return 0;
}