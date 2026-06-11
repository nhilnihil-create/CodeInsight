#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int mx = N - K + 1;
    int mn = (K > 1) ? 1 : (N - K + 1);
    cout << mx - mn << endl;
    return 0;
}