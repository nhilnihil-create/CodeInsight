# include <iostream>
# include <math.h>

using namespace std;

int main()
{
    char letter;

    cin >> letter;

    if (letter > 64 && letter < 91)
        cout << "A";
    else
        cout << "a";

    return 0;
}