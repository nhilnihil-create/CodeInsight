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
    long long a, b;
    cin >> a >> b;
    long long A = min(a, b), B = max(a, b);
    long long r = B % A;
    while(r != 0){
        B = A;
        A = r;
        r = B % A;
    }
    long long gcd = A;
    long long ans = a * b / gcd;
    cout << ans << endl;
    return 0;
}