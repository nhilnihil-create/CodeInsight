#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int cnt = 0;
    while(n)
    {
        int rem = n % 10;
        if(rem == 7)
            cnt++;

        n /= 10;
    }
    if(cnt)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
