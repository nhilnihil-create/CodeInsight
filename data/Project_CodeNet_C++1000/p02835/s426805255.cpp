#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (a+b+c>=22)
    printf("bust\n");
    else
    printf("win\n");
    return 0;
}