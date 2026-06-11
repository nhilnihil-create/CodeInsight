#include <iostream>
#include<cmath>

using namespace std;

int main()
{

    int A, B;
    cin >> A >> B;
    float minA, maxA, minB, maxB, minP, maxP;
    minA = A / 0.08;
    maxA = (A + 1) / 0.08;
    minB = B / 0.1;
    maxB = (B + 1) / 0.1;
    minP = max(minA, minB);
    maxP = min(maxA, maxB);

    int ans = ceil(minP);
    if(ans >= maxP){
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}