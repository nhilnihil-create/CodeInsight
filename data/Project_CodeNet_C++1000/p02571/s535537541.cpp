#include <iostream>
using namespace std;
string s, ss;
int main()
{
    cin >> s >> ss;
    int mn = 0x3F3F3F3F;
    for(int i = 0;i <= s.length() - ss.length();i++)
    {
        int cnt = 0;
        for(int j = 0;j < ss.length();j++)
        {
            if(s[i + j] != ss[j])
                cnt++;
        }
        mn = min(mn, cnt);
    }
    cout << mn;
    return 0;
}
