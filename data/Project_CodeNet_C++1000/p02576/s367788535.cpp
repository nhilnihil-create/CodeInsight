#include <iostream>
#include <cmath>

using namespace std;

int n,x,t;

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> n >> x >> t;
    int ans = (int)(ceil((double)n/(double)x)*t);
    cout<< ans << endl;

    return 0;
}
