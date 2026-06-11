#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(2*b>=a)
        cout<<"0\n";
    else
        cout<<a-2*b<<"\n";
}