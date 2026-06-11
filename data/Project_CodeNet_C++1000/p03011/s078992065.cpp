#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int P , Q , R , S ;
    cin >> P >> Q >> R ;
    S = fmin(P , fmax(Q , R));
    Q = fmin( Q , R);
    cout << S + Q << endl;
    return 0;
}
