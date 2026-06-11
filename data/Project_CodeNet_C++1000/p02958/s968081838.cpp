#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin>>n;
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(i!=x)
            cnt++;
    }
    if(cnt<=2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}