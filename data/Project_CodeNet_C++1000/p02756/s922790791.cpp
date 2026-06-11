#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;

    bool rev = false;
    string front, end;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
            rev = !rev;
        else
        {
            int f;
            char c;
            cin >> f >> c;
            bool rf = bool(f - 1);
            if (rf == rev)
                front += c;
            else
                end += c;
        }
    }
    reverse(front.begin(), front.end());
    s = front + s + end;
    if (rev)
        reverse(s.begin(), s.end());
    cout << s << endl;
}