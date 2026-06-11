#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int x;
    cin >> x;

    int  a = x / 500;
    int b = (x % 500) / 5;
    int ans = (a * 1000) + (b * 5);
    cout << ans << endl;


}
