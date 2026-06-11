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
    long long a, b, k;
    cin >> a >> b >> k;
    a -= k;
    if(a <= 0){
        k = abs(a);
        a = 0;
        b -= k;
        if(b <= 0) b = 0;
    }
    cout << a << " " << b << endl;
    return 0;
}