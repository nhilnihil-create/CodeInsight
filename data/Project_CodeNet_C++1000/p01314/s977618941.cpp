#include <iostream>
#include <vector>
using namespace std;

int acc(int a, int b) {
	if(a < b) throw "Error";
	
	return a * (a + 1)  / 2 - b * (b + 1) / 2;
}

int main() {
	for(int n; cin >> n && n; ) {
		int answer = 0;
		
		for(int top = 1, tail = 0; top <= 1000; top++) {
			while(true) {
				if(top - tail > 1 && acc(top, tail) == n) {
					answer++;
				}
				
				if(acc(top, tail) > n) {
					tail++;
				} else {
					break;
				}
			}
		}
		
		cout << answer << endl;
	}
}