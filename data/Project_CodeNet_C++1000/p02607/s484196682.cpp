#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, i, ans=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(i%2==1 && x%2==1)
            ans++;
    }
    cout  << ans << endl;
    return 0;
}
