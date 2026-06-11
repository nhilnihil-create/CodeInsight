#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    long long a,b,p,q,i;
    cin>>a>>b;
    p=max(a,b);
    q=min(a,b);
    for(i=1;i<=p;i++)
    {
        cout<<q;
    }
    cout<<endl;
    return 0;
}