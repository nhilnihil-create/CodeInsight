#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int A, B ,C;
    cin >> A >> B >> C;
    cout << (C-(A-B)>=0?C-(A-B):0);
}
