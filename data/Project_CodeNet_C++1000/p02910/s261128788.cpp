#include <iostream>
#include <string>

using namespace std;

using std::string;

int main()
{
    string a;
    cin >> a;

    bool isPlayable = true;

    for (int i = 1; i <= a.length(); i++)
    {
        if ((i % 2) == 0)
        {
            if (a[i - 1] == 'R')
            {
                isPlayable = false;
                break;
            }
        }
        else
        {
            if (a[i - 1] == 'L')
            {
                isPlayable = false;
                break;
            }
        }
    }

    if (isPlayable)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}