#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<10)
    {
        a=(100*(10-a));
        b+=a;
        cout<<b<<endl;
    }
    else
    {
        cout<<b<<endl;
    }
    return 0;
}
