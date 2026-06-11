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
    long long int a,b,k;
    cin>>a>>b>>k;
    long long int c=a+b-k;
    if (a+b<k)      {cout<<"0 0";}
    else if (c>b)   {cout<<c-b<<" "<<b;}
    else            {cout<<"0 "<<c;}
    return 0;
}