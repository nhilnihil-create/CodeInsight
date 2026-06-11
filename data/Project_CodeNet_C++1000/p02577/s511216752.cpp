#include <iostream>
#include <string>
using namespace std;

int main()
{
    string N;
    int len, sum;
    cin >> N;
    len = N.length();
    for (int i = 0; i < len; i++)
    {
        sum += N[i] - '0';
    }
    if (sum % 9 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}