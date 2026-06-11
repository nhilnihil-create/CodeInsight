#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    int count1 = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
        {
            count1++;
            //i = i + 3;
        }
    }

    cout << count1;

    return 0;
}





