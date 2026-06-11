#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    repi(i, h, 0)
    {
        string s;
        repi(j, w, 0)
        {
            if (i < b)
            {
                if (j < a)
                {
                    s.push_back('0');
                }
                else
                {
                    s.push_back('1');
                }
            }
            else
            {

                if (j < a)
                {
                    s.push_back('1');
                }
                else
                {
                    s.push_back('0');
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}