#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int val=a-(2*b);
    if (val>0)
      printf("%d\n",val);
    else
      printf("0\n");
    return 0;
}