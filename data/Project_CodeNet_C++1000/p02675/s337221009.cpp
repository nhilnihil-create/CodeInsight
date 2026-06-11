#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    N %= 10;
    if (N == 2 || N == 4 || N == 5 || N == 7 || N == 9)
    {
        cout << "hon" << endl;
        return 0;
    }
    else if (N == 0 || N == 1 || N == 6 || N == 8)
    {
        cout << "pon" << endl;
        return 0;
    }
    else
    {
        cout << "bon" << endl;
        return 0;
    }
}