#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
    string number;
    cin >> number;
    long total = 0;
    char cToStr[2];
    cToStr[1] = '\0';
    for (int i = 0; i < number.length(); i++) {
        cToStr[0] = number[i];
        total += atoi(cToStr);
    }
    if (total % 9 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
	return 0;
}

