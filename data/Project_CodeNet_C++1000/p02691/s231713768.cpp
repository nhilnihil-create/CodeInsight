#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, n, a[200600], C[200010], ans;
bool cond;
int main()
{
    //I am Monim, a tiny creature of Allah
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]<i)
            ans += C[i-a[i]];
        if(a[i]+i<=n)
            C[a[i]+i]++;
    }
    cout << ans << endl;
    return 0;
}
