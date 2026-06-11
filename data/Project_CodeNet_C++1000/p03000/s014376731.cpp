#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n, x, l, d=0;
    int count = 1;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        d += l;
        if(d <= x) count++;
    }
    cout << count << endl;
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
