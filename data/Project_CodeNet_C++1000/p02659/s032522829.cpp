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
    long long int a;
    float b;
    cin>>a>>b;
    int c=100.05*b;
    cout<<fixed<<setprecision(0)<<a*c/100;
    return 0;
}