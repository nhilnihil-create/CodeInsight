#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int tc;
int a[N], b[N];
int main()
{
    FIO
    int n; 
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    if(n%2)
        cout<< b[n/2] - a[n/2] + 1 <<endl;
    else
        cout<<b[n/2] + b[(n/2) - 1] - a[n/2] - a[n/2 - 1] + 1;
    return 0;
}