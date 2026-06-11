#include <bits/stdc++.h>
using namespace std;

void Main()
{
    long w, h, x, y;
    cin >> w >> h >> x >> y;
    int f = 0;
    if(x*2 == w && y*2 == h) f = 1;
    cout << fixed << setprecision(15) 
        << w*h/2.0 << " " << f << endl;
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
