#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,sum,sum2,sum3;
    cin>>a;
    sum= a/500;
    sum2= a%500;
    sum3 = sum2/5;
    cout<<sum*1000+sum3*5<<endl;


    return 0;
}