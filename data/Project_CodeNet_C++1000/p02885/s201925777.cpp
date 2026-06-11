#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int result=abs(a-2*b);

    if(a<2*b)
        cout<<0<<endl;
    else
        cout<<result<<endl;
    exit(0);
}
