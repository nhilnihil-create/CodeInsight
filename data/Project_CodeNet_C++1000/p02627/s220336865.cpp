#include <iostream>
using namespace std;

int main() {
	char word;
	cin >> word;
	if (0 <= (word - 'a') && (word - 'a') <= 25) cout << "a" << endl; else cout << "A" << endl;
}