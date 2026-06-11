


#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i;
    cin>>n;

    long long sum=0;
    for(int i=0; i<=n; i++)
    {
        if(i%3!=0 && i%5!=0)
            sum=sum+i;
    }

    cout<<sum<<endl;

}
