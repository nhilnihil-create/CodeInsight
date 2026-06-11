#include<iostream>
using namespace std;

int main(void){
	int time;
	cin >> time;
	int s = 0, m = 0, h = 0;

	s = time % 60;
	time /= 60;
	m = time % 60;
	h = time / 60;

	cout << h << ":" << m << ":" << s << endl;
	return 0;
}