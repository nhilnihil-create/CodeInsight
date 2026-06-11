#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 1000; i++)
    {
        c -= b;
        if(c <= 0){
            cout << "Yes" << endl;
            return;
        }
        a -= d;
        if(a <= 0){
            cout << "No" << endl;
            return;
        }
    }
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
