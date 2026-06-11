#include<stdio.h>
#include<iostream>
#include<cmath>
#define maxn 1e7+7
using namespace std;
int main()
{
    int k;long long num=0,sum=0;
    cin>>k;
    bool flag=0;
    for(int i=0;i<maxn;i++)
    {
        num=(num*10+7)%k;
        if(num%k==0)
        {
            flag=1;
            sum=i+1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<sum<<endl;
    }
    else
        cout<<"-1"<<endl;
}
