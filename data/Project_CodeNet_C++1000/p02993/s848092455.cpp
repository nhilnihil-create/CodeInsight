#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    int flag = 0;
    cin >> S;
    for (int count = 0; count < 3; count++)
    {
        if (S.at(count) == S.at(count + 1))
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << "Bad" << endl;
    }
    else
    {
        cout << "Good" << endl;
    }
}