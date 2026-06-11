
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    string p;

    cin >> p;

    int cnt=0,i;

    for(i=0;i<n;i++)
    {
        if(p[i]=='A' && p[i+1]=='B' && p[i+2]=='C')
        {
            cnt++;

            i=i+2;
        }
    }

    cout << cnt << endl;

    return 0;
}
