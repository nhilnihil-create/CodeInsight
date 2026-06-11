#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    a-=b;
    if(c<=a)cout << 0;
    else cout << c-a;
}
