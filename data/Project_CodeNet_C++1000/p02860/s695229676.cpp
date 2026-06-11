//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin>> s;
    if (n%2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    for(int i=0;i<n/2;i++)
    {
        if (s[i]!=s[i+n/2])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;

}


