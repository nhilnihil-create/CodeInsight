#include <bits/stdc++.h>
using namespace std;


int main()
{
    int k;
    string s;
    cin >> k >> s;

    int size = s.size();
    if(size <= k)
    {
        cout << s << "\n";
    } else
    {
        cout << s.substr(0, k) + "..." << "\n";
    }
    return 0;
}