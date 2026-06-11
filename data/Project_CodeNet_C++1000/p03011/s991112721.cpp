#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI = (acos(-1));
const long long MOD = pow(10, 9) + 7;
long long kaizyou(int N);
long long POW(int J);

bool judge(int dt, int dx, int dy);

int main()
{
    int P,Q,R;
    cin >> P >> Q >> R;

    int s[3];
    s[0] = P + Q;
    s[1] = P + R;
    s[2] = Q + R;

    int mini = s[0];
    for(int i=1; i<3; i++)
    {
        if(mini > s[i])
        {
            mini = s[i];
        }
    }

    cout << mini;
    
}
