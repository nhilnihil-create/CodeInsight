#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int ele,cnt=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        if (ele>=k)
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}