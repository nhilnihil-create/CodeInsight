#include <iostream>
using namespace std;
int main()
{
    bool reverse = false;
    string s;
    cin >> s;
    int n, front = 0, back = 0;
    cin >> n;
    char f[n], b[n];
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            reverse = !reverse;
        }
        else
        {
            int y;
            cin >> y;
            if((reverse && y == 2) || (y == 1 && !reverse))
            {
                cin >> f[front++];
            }
            else
            {
                cin >> b[back++];
            }
        }
    }
    if(reverse)
    {
        for(int i = back - 1; i >= 0; i--)
        {
            cout << b[i];
        }
        for(int i = s.size() - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        for(int i = 0; i < front; i++)
        {
            cout << f[i];
        }
    }
    else
    {
        for(int i = front - 1; i >= 0; i--)
        {
            cout << f[i];
        }
        cout << s;
        for(int i = 0; i < back; i++)
        {
            cout << b[i];
        }
    }
    cout << endl;
    return 0;
}
