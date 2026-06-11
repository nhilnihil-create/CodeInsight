#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin >> str;
    const char sunny = 'S';
    int rainStreak = 3;
    int countSunny = 0;
    for (int i = 0; i < 3; i++)
    {
        if (str[i] == sunny) {
            countSunny += 1;
        }
    }
    rainStreak -= countSunny;
    if (countSunny == 1 && str[1] == sunny) {
        rainStreak -= 1;
    }
    cout << rainStreak;
	return 0;
}

