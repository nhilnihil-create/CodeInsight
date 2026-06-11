#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    long long a, B, mult, ans;
    double b;
    cin >> a >> b;
    B = b * 100 + 0.5;
    mult = a * B;
    ans = mult / 100;
    cout << ans << endl;
    return 0;
}