#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,ans;
    cin >> n >> d;

    int scope = (2*d+1);

    if(n%scope == 0)
        ans = n/scope;
    else
        ans = n/scope + 1;
    
    cout << ans << endl;
    return 0;
}