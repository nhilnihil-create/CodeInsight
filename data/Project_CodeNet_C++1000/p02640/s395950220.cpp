#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(b%2==0 && b>=a*2 && b<=a*4)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
