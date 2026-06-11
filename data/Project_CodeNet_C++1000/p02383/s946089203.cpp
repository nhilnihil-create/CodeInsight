#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>

#define PI 3.14159265359
using namespace std;


int main(){
	int tmp;
	vector<int> d(6);
	for (int i = 0; i < 6; i++) cin >> d[i];
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'W'){
			tmp = d[3];
			d[3] = d[0];
			d[0] = d[2];
			d[2] = d[5];
			d[5] = tmp;
		}
		else if (s[i] == 'E'){
			tmp = d[5];
			d[5] = d[2];
			d[2] = d[0];
			d[0] = d[3];
			d[3] = tmp;
		}
		else  if (s[i] == 'N'){
			tmp = d[0];
			d[0] = d[1];
			d[1] = d[5];
			d[5] = d[4];
			d[4] = tmp;
		}
		else {
			tmp = d[4];
			d[4] = d[5];
			d[5] = d[1];
			d[1] = d[0];
			d[0] = tmp;
		}
	}
	cout << d[0] << endl;
}