#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n  , ans=0 , x;
    cin >> n;
    for(int i = 1;  i<=n ; i++)
    {
        cin >> x;
        if(i%2==1&&x%2==1)
            ans++;
    }
    cout << ans;
    return 0;
}
