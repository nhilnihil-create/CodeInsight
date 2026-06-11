#include<iostream>
using namespace std;
int main()
{
    long long n,i,j,three=0,total,five=0;
    cin>>n;
    for(i=3;i<=n;i+=3)
    {
        three+=i;
    }
    for(j=5;j<=n;j+=5)
    {
        if(j%3!=0)
        {
            five+=j;
        }
    }
    total=(n*(n+1))/2;
    total=total-(three+five);
    cout<<total<<endl;
    return 0;
}