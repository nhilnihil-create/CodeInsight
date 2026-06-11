#include <iostream>
#include <string>
using namespace std;

int main()
{
    int A, B;
    string S, T, U, all;
    getline(cin, all);
    S = all.substr(0, all.find(" "));
    T = all.substr((all.find(" ")+1));
    cin >> A >> B;
    cin.ignore();
    getline(cin,U);
    if (U == S)
        A = A - 1;
    if (U == T)
        B = B - 1;

    cout << A << " " << B;
    return 0;
}

