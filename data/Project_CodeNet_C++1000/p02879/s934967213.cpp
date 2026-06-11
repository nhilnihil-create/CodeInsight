#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>9 || a<1 || b>9 || b<1)
        cout<<"-1";
    else cout<<a*b;
    return 0;
}
