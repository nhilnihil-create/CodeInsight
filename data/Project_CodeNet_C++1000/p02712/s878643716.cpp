#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
#include <iostream>
using namespace std;
///int a[1005];
int main()
{
   int n;
   cin>>n;
   long long sum=0;
   for(int i=1;i<=n;i++)
   {
    if(i%3==0||i%5==0)
        sum+=0;
    else
        sum+=i;
   }
    cout<<sum<<endl;
    return 0;
}
