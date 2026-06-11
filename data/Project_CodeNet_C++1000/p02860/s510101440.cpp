#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int flag = 1;
    if(n%2!=0)
    {
       flag = 0;
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[i+n/2])
            {
                flag=0;
            }
           /// cout << flag << endl;
        }
    }
    if(flag==1)
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
