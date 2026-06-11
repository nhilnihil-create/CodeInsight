#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int h;
    cin >> h;
    long long int ans = 0;
    long long int cur;
    long long int k = 0;
    h /= 2;
    while(h){
        k++;
        h /= 2;
    }

    ans = pow(2, k+1) - 1;

    cout << ans << endl;
    return 0;
}