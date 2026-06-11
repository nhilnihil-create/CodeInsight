#include <iostream>
#include <cstdio>
using namespace std;
int v[200005],n;
int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        for (int i = 0; i < n; ++i)
                cin >> v[i];

        int total_xor = 0;

        for(int i = 0; i < n; i++)
                total_xor ^= v[i];

        for(int i = 0; i < n; i++)
                cout << (total_xor ^ v[i]) << ' ';

        return 0;
}
