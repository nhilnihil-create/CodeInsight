#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    int N;
    cin >> N;
    int ans = (N%2)? N/2 : N/2 - 1;
    cout << ans << endl;
    return 0;
}