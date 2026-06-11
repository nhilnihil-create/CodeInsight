#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if (x>=10 || y>=10)
    printf("-1\n");
    else
    printf("%d\n",(x*y));
    return 0;
}