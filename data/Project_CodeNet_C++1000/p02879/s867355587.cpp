#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if(A>=10)
        cout << "-1" << endl;
    else if(B>=10)
        cout << "-1" << endl;
    else
        cout << A*B << endl;
    return 0;
}