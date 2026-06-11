#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    int ans;

    ans = min(a+b,a+c);
    ans = min(ans, b+c);

    cout << ans << endl;

}