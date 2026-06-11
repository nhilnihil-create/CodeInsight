#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char s[n], t[n];
    cin >> s >> t;
    for(int i = 0; i < n; i++)
    {
        cout << s[i] << t[i];
    }
    return 0;
}