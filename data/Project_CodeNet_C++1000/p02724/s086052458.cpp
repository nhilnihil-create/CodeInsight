#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int sum=0;
    while(x>=500)
    {
        x=x-500;
        sum=sum+1000;
    }

    while(x>=5)
    {
        x=x-5;
        sum=sum+5;
    }
    cout<<sum;

}
