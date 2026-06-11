#include<iostream>
using namespace std;
int main()
{
    int n, k, h, ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> h;
        if(h >= k)
            ans++;
    }
    cout << ans;
    return 0;
}