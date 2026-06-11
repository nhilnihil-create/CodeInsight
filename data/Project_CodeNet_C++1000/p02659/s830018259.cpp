#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,mul;
    double b;
    cin>>a>>b;
    mul = round(b*100);
    mul = (a*mul)/100;
    cout<<mul;
    return 0;
}
