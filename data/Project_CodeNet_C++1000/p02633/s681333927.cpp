#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x, k=1;
    cin >> x;
    while(x*k%360 != 0) k++;
    cout << k << endl;
    return 0;
}