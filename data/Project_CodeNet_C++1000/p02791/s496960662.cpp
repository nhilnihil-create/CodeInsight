#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int i,n,mn,c=0;
    cin >> n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    mn=a[0];
    for(i=0; i<n; i++)
    {
        if(mn>=a[i])
        {
            c++;
            mn=a[i];
        }
    }
    cout << c << endl;
    return 0;
}
