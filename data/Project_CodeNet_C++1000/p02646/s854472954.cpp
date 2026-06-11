#include <iostream>
using namespace std;
int main()
{
    long long a,v,b,w,t,d;
    cin>>a>>v>>b>>w>>t;
    if(a>b)
        d=a-b;
    else
        d=b-a;
    if(w>=v)
        cout<<"NO"<<endl;
    else if(t*(v-w)<d)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}