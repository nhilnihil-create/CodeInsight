#include<iostream>
using namespace std;
int main()
{
    int n, i = 0;
    string s;
    cin >> n >> s;
    while(s[i] == s[n/2 + i] && i < n/2)
    {
        i++;
    }
    if(n % 2 == 0 && i == n/2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
