#include <iostream>
#include <stack>
#define REP(i,n) for(int i = 1; i < n; i++)

using namespace std;

int main() {
	REP(i,10){
		REP(j,10){
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
}