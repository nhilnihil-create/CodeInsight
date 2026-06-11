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

long long int sum(long long int x)
{
    return x*(x+1)/2;
}

int main()
{
    long long int n;
    cin>>n;
    cout<<sum(n)+15*sum(n/15)-3*sum(n/3)-5*sum(n/5);
    return 0;
}
