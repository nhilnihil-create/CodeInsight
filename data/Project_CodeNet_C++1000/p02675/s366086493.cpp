#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, rem;
    string res;
    cin >> n;
    rem = n >= 10 ? n % 10 : n;
    
    if(rem == 3)
    {
        cout << "bon" << "\n";
    } else if(rem == 2 || rem == 4 || rem == 5 || rem == 7 || rem == 9)
    {
        cout << "hon" << "\n";
    } else 
    {
        cout << "pon" << "\n";
    }
    return 0;
}