#include <iostream>
#include <string>
using namespace std;
main()
{
    int a,b,n,i;
    a=b=i=0;
    cin>>n;
    for(;i<n;i++){
        string t,h;
        cin>>t>> h;
        a+=(t>h)*3+(t==h);
        b+=(h>t)*3+(t==h);
    }
    cout<<a<<" "<<b<<endl;
}