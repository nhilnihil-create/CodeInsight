#include <iostream>
using namespace std;

int isIn(int x, int min, int max) {
    return min <= x && x <= max;
}

int getGrade(int rating) {
    if (isIn(rating, 400, 599)) return 8;
    else if (isIn(rating, 600, 799)) return 7;
    else if (isIn(rating, 800, 999)) return 6;
    else if (isIn(rating, 1000, 1199)) return 5;
    else if (isIn(rating, 1200, 1399)) return 4;
    else if (isIn(rating, 1400, 1599)) return 3;
    else if (isIn(rating, 1600, 1799)) return 2;
    else if (isIn(rating, 1800, 1999)) return 1;
    else return 0;
}

int main()
{
    int x;
    cin >> x;

    cout << getGrade(x) << endl;
    
    return 0;
}
