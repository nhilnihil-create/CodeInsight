#include <iostream>
using namespace std;

int main(void) {
	int time;
	cin >> time;
	int second = time % (60 * 60) % 60;
	int minute = time % (60 * 60) / 60;
	int hour = time / (60 * 60);
	cout << hour << ":" << minute << ":" << second << endl;
	return 0;
}
