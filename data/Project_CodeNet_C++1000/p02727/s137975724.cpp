#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x, y, a, b, c, z = 0, cnt = 0;
    long long ans = 0;
    cin >> x >> y >> a >> b >> c;
    int rd[a], gr[b], cl[c], mix[x + y + c];
    for(int i = 0; i < a; i++)
    {
        cin >> rd[i];
    }
    for(int i = 0; i <b; i++)
    {
        cin >> gr[i];
    }
    for(int i = 0; i< c; i++)
    {
        cin >> cl[i];
    }
    sort(rd, rd + a);
    sort(gr, gr + b);
    sort(cl, cl + c);
    for(int i = a - 1; i >= a - x; i--)
    {
        mix[z++] = rd[i];
    }
    for(int i = b - 1; i >= b - y; i--)
    {
        mix[z++] = gr[i];
    }
    for(int i = c - 1; i >= 0; i--)
    {
        mix[z++] = cl[i];
    }
    sort(mix, mix + z);
    for(int i = z - 1; i >= z - x - y; i--)
    {
        ans += mix[i];
    }
    cout << ans << endl;
}


