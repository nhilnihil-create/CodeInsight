#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    if(N%2) cout << N/2 << endl;
    else cout << N/2 - 1 << endl;

    return 0;
}
