#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    int flag=0,val;
    for (int i=x;;i++)
    {
        flag=0;
        for (int j=2;j*j<=i;j++)
        {
            if (i%j==0)
            {
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            val=i;
            break;
        }
    }
    printf("%d\n",val);
    return 0;
}
