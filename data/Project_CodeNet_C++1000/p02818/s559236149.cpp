#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int A,B,K,d,p,t;
    cin>>A>>B>>K;
    t=A+B;
    d=K-A;
    if(t<=K)
        cout<<"0"<<" "<<"0"<<endl;
    else if(d>=0)
    {
        p=B-d;
        cout<<"0"<<" "<<p<<endl;
    }
    else
        cout<<A-K<<" "<<B<<endl;
}