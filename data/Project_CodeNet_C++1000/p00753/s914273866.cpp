#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int cnt;
int n;
bool func(int num)
{
    if(num==2)return true;
    else if(num%2==0)return false;
    else if(num==1)return false;
    else
    {
        for(int i=3;i<=sqrt(num);i+=2)
        {
            if(num%i==0)return false;
        }
    }
    return true;
}
int main()
{
    while(cin>>n,n)
    {
        cnt=0;
        for(int i=n+1;i<=2*n;i++)
        {
            if(func(i))
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}