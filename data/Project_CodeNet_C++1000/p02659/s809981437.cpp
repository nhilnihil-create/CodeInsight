#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t;
    t = 1;
    for(int i=0;i<t;i++)
    {
        ll a;
        double b;
        cin>>a>>b;
        ll z = a * int(b*100+0.1)/100;
        cout<<z;
    }
    return 0;
}