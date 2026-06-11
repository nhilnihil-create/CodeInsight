#include<bits/stdc++.h>
using namespace std;
long long int K, P, r, ans;
int main()
{
    cin >> K;
    P = 100;
    while(true)
    {
        P = P + (P/100);
        ans++;
        if(P>=K)
            break;
    }
    cout << ans << endl;
    return 0;
}
