#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int a,b;
    cin >> a;
    cin >> b;
    long double n = (a + (double)b)/2;
    if(ceil(n) == floor(n))
        cout << (long long int)n;
    else
        cout << "IMPOSSIBLE";
    return 0;
}
