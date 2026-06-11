#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;
int main()
{
    Tayeb;
    int X,sum1=0,sum2=0;
    cin >> X;
    sum1=(X%500)-((X%500)%5);
    sum2=(X/500)*1000;
    cout << sum1+sum2 << "\n";
    
    return 0;

}
