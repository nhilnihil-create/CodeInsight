#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>


using namespace std;

int main(){
	
	int answer;

	int s = 0, t = 0;
	int ibuf;

	for (int i = 0; i < 4; i++) {
		cin >> ibuf;
		s += ibuf;
	}
	for (int i = 0; i < 4; i++) {
		cin >> ibuf;
		t += ibuf;
	}

	answer = max(s, t);

	cout << answer << endl;

	return 0;
}
