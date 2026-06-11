#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >>n >>m;
    int s[6],c[6];
    for(int i=0;i<m;i++) 
        cin >>s[i] >>c[i];
    for(int i=0;i<=999;i++)
    {
        string str = to_string(i);
        if(str.size()==n)
        {
            int cnt = 0;
            for(int j=0;j<m;j++)
            {
                if(str[s[j]-1]!=c[j]+'0') 
                    break;
                else cnt++;
            }
            if(cnt==m)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
