#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
typedef long long ll;
int main()
{
    int x,y500,n,y5,ans;
    cin >> x;
    y500 = 1000*(x/ 500);
    n = x % 500;
    y5 = 5 * (n / 5);
    ans = y500 + y5 ;
    cout << ans<< endl;

    return 0;

}