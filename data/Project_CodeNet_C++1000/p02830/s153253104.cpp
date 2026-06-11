#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin >> N;
    string S, T;
    cin >> S >> T;
    string ans;
    rep(i, 0, N)
    {
        ans.push_back(S[i]);
        ans.push_back(T[i]);
    }
    cout << ans << endl;
}
int main()
{
    func();
}