#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int K;
    cin >> K;
    if (K % 7 == 0)
    {
        K /= 7;
    }
    K *= 9;
    ll test = 1;
    for (int i = 1; i <= K; i++)
    {
        // cout<<test<<endl;
        test = test * 10 % K;
        if (test == 1)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
