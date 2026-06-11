#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >>a;
    int ans;
    for(int i=1; ;i++)
    {
        if((a*i)%360==0)
        {
            ans=i;
            break;
        }
    }
    cout << ans << endl;
}