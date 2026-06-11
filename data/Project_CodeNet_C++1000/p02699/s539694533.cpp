#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
int N, M;
void func()
{
    cin >> N >> M;
    if (M >= N)
        cout << "unsafe" << endl;
    else
    {
        cout << "safe" << endl;
    }
}
int main()
{
    func();
}