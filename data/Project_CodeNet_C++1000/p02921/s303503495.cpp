#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    char S[3],T[3];
    cin >> S;
    cin >> T;
    for (int i; i < 3;i++)
    {
        if (S[i]== T[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
