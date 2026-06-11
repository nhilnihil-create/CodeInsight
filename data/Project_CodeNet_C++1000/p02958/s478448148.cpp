#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[60], b[60], i, cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a, a+n);
    for(i=0; i<n;i++)
    {
        if(a[i]!=b[i])
            cnt++;
    }
    if(cnt<=2)
        cout<<"YES";
    else
        cout<<"NO";

}
