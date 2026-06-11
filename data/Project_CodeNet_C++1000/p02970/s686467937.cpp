#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int D;
	double N;
	cin >> N >> D;
	cout << ceil(N / (D*2+1)) << endl;
	return 0;
}