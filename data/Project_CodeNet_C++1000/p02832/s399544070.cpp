#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==(cnt+1))
        cnt++;
    }
    if (cnt==0)
    printf("-1\n");
    else
    printf("%d\n",(n-cnt));
    return 0;
}
