#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    map<long long, long long> pp, p;
    long long m, n, a, s = 0, ss = 0, i;
    string ks;
    cin >> m >> n;
    while (n--)
    {
        cin >> a >> ks;
        if (ks[0] == 'W' && p[a] == 0)
            pp[a]++;
        else if (ks[0]=='A')
            p[a]++;
    }//cout<<p[0];
    for (i = 1; i <= m; i++)
    {
        if (p[i] > 0)
        {
            s++;
            ss += pp[i];
        }
    }
    cout << s << " " << ss;
}