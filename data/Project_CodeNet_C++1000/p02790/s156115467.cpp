#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;

   // cin>>t;
    while(t--)
    {
       int n,m,i;
       cin>>n>>m;
       if(n>m)
        swap(n,m);
       for(i=0;i<m;i++)
        cout<<n;
    }
}
