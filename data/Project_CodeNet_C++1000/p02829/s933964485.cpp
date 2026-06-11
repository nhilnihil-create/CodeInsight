#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if((a==1 || a==2) && (b==1 || b==2))
        cout<<3<<endl;
    else if((a==2 || a==3) && (b==2 || b==3))
        cout<<1<<endl;
    else
        cout<<2<<endl;
    return 0;
}
