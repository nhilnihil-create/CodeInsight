#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    int q;

    cin >> s >> q;

    long long x;
    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            x++;
        }
        else
        {            
            int f;
            string c;
            cin >> f >> c;

            if ((f == 1 && !(x % 2)) || (f == 2 && x % 2))
            {
                s = c + s;
            }
            else
            {
                s += c;
            }
            
        }
        
    }

    if (x % 2) reverse(s.begin(), s.end());

    cout << s << endl;
}