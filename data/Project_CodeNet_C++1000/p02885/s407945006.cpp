#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    a-=2*b;
    if(a<0) a=0;
    cout << a << endl;
}