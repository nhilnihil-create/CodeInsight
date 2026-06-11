#include <bits/stdc++.h>
using namespace std;

void Main()
{
    long n, a, b;
    cin >> n >> a >> b;
    long blue = n / (a + b) * a;
    long hasu = n % (a + b);
    if(hasu <= a) blue += hasu;
    else blue += a;
    cout << blue << endl;
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
