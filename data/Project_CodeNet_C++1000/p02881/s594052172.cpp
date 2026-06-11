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
    long long n;
    cin >> n;
    long long div = pow(n, 0.5), i = div;
    while(n % i != 0) i--;
    long long ans = i + (n / i) - 2;
    cout << ans << endl;
    return 0;
}