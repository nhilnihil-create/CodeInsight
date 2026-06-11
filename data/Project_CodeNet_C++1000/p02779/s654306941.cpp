#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<long long, long long> m;

int main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        if (m.find(x) == m.end())
        {
            m[x] = 1;
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
        
    }

    cout << "YES\n";
}