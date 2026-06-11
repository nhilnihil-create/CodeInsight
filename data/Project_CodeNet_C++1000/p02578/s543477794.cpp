#include <iostream>
using namespace std;
int N,P,A;
long ans;
main()
{
    cin>>N;
    while(cin>>A)
    {
        if(P<=A)P=A;
        else ans+=P-A;
    }
    cout<<ans<<endl;
}