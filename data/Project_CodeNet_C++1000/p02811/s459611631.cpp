#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    if (x<=(500*n))
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}