#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);

    char a, b, c;

    cin >> a >> b >> c;

    if(a == 'R' && b == 'R' && c == 'R')
        cout << 3;
    else if(a == 'R' && b == 'R' || b == 'R' && c == 'R')
        cout << 2;
    else if(a == 'R' || b == 'R' || c == 'R')
        cout << 1;
    else
        cout << 0;


    return 0;

}
