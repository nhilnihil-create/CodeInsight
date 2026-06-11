#include <iostream>

using namespace std;

int main()
{
    int N;
    bool seven = false;

    cin >> N;

    for (int i = 0; i < 3; i++)
    {
        if (N % 10 == 7)
        {
            seven = true;
        }
        N /= 10;
    }
    if (seven)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}