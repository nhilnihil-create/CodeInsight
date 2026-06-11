#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S, T;
    cin>>S>>T;
    int ans = 1001;
    int l1 = S.length(), l2 = T.length();
    for (int i=0; i<=(l1-l2); i++) {
        int c = 0;
        for (int j=0; j<l2; j++) {
            if (S[i+j] != T[j]) c++;
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';
    return 0;
}