#include<bits/stdc++.h>
using namespace std;

#define int long long

int N;

signed main()
{
    cin >> N;
    if(N & 1) cout << 0 << endl;
    else
    {
        int ans = 0;
        for(int i = 5; i * 2 <= N; i *= 5)
        {
            ans += N / (i * 2);
        }
        cout << ans << endl;        
    }
    
    return 0;
}