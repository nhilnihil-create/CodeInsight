#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    if(r>9)cout << c;
    else cout << c+100*(10-r);
}
