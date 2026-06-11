#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A, B, C, K, cnt = 0;
    cin >> A >> B >> C >> K;
    while(A >= B)
    {
        cnt += 1;
        B *= 2;
    }
    while(B >= C)
    {
        cnt += 1;
        C *= 2;
    }
    if(cnt <= K) cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}