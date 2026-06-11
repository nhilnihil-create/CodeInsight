#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
//ll number[20],used[20];
int main()
{
    ll n,i,a,count,sum;
    cin >> n >> a;
    sum = n/a;
    if(n%a==0)
        cout << sum << endl;
    else
    {
            cout << sum+1 << endl;
    }
    return 0;
}
