#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, ans; string A, B, S;
int main()
{
    cin>>S; for(int i = 0; i < S.size(); ++i) A += S[i], A != B?(B = A, A = "", ++ans):0;
    printf("%d\n", ans);
    return 0;
}