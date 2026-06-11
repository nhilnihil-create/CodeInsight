#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int p,q,r,k;
    cin>>p>>q>>r>>k;
    if(k<=p)
        cout<<k<<endl;
    else if(k<=(p+q))
        cout<<p<<endl;
    else
        cout<<p-(k-p-q)<<endl;
    return 0;
}
