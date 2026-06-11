#include<iostream>
using namespace std;
int main()
{
    string s, p = "";
    int k;
    cin >> k >> s;
    if(s.size() <= k)
        cout << s;
    else
    {
        for(int i = 0; i < k; i++)
        {
             p = p + s[i];
        }
        cout << p << "...";
    }
    return 0;
}