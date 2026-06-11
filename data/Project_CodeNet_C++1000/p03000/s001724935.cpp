#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, k = 0, x, d[1000];
    cin >> n >> x;
    d[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        d[i + 1] = d[i] + p;
    }
    for(int i = 0; i <= n; i++)
    {
        if(d[i] <= x)
            k++;
    }
    cout << k;
    return 0;
}