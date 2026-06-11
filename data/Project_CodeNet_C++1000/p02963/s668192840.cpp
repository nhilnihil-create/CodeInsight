#include <bits/stdc++.h>
#define N 1000099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
// ios::sync_with_stdio(false);
using namespace std;
int n;
LL S;
int main()
{
    cin >> S;
    LL t = sqrt(S);
    if (t * t < S)
        t++;
    cout << "0 0 " << t << " " << t * t - S << " 1 " << t << endl;
    return 0;
}
