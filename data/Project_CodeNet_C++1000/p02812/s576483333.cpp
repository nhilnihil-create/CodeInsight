#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c = 0;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    for(int i = 0; i < n-2; i++)
    {
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
        {
            c++;
            i += 2;
        }
    }
    cout << c ;
}
