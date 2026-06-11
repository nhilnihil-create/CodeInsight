#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	while(1){
		int n;
		cin >> n;
		if(!n) break;
		vector <int> s(n);
		double ave=0, hensa=0;
		for(int i=0;i<n;i++){
			cin >> s[i];
			ave += s[i];
		}
		ave /= n;
		for(int i=0;i<n;i++){
			hensa += (s[i]-ave)*(s[i]-ave);
		}
		hensa = sqrt(hensa/n);
		cout << fixed << setprecision(12) <<  hensa << endl;
	}
	return 0;
}