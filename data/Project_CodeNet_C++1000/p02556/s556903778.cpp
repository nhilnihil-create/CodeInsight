#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int d1[200005],d2[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        d1[i]=x+y;
        d2[i]=x-y;
    }
    sort(d1,d1+n);
    sort(d2,d2+n);
    cout<<max(d1[n-1]-d1[0],d2[n-1]-d2[0])<<endl;
    return 0;
}
