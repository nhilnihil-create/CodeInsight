#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if (a>=1 && a<=9 && b>=1 && b<=9)
    printf("%d\n",(a*b));
    else
    printf("-1\n");
    return 0;
}