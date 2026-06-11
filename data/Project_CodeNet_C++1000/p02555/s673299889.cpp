#include <iostream>
using namespace std;
int n,i,j,a[2001];
int main()
{
    cin>>n;
    a[3]=1;
    a[4]=1;
    a[5]=1;
    for(i=6;i<=2000;i++)
    {
        a[i]=((a[i-2]+a[i-3])%1000000007+a[i-4]%1000000007)%1000000007;
    }
    cout<<a[n]<<endl;
    //system("pause");
    return 0;
}
