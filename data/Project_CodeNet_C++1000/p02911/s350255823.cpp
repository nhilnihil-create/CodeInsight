#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int a[n+1]={0};
    for (int i=0;i<q;i++)
    {
        int ele;
        scanf("%d",&ele);
        a[ele]++;
    }
    for (int i=1;i<=n;i++)
    {
        if ((k-(q-a[i]))<=0)
        printf("No\n");
        else
        printf("Yes\n");
    }
    return 0;
}