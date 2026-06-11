#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, temp,t, n,j, a, b, c, k, ans;
bool cond;
int main()
{
    //I am Monim, a tiny creature of Allah
    cin >> a >> b >> c >> k;
    temp = min(a,k);
    ans = temp;
    if(temp<k)
        temp += min(b,k-a);
    if(temp<k)
    {
        temp += min(c, k-(a+b));
        ans -= min(c, k-(a+b));
    }
    cout << ans << endl;
    return 0;
}

