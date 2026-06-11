#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<iterator>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long int>fac(n+1,0);
    int i=1;
    while(i<=n)
    {
        int j=1;
        while (i*j<=n)
        {
            fac[i*j]++;
            j++;
        }
        i++;
    }
    i=1;
    long long int sum=0;
    while(i<=n)
    {
        sum=sum+fac[i]*i;
        i++;
    }
    cout<<sum;
    return 0;
}