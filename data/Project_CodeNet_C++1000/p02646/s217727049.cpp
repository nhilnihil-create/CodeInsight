
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    if(v<w)
        cout<<"NO"<<endl;
    else if((v-w)*t>=abs(a-b))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
