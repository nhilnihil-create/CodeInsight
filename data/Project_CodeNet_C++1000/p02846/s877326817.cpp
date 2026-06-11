#include<bits/stdc++.h>
using namespace std;

using Lint=long long;

Lint solve(Lint X,Lint Y)
{
    if(X<0) X=-X,Y=-Y;
    if(X==0) return 1;
    else{
        if(X+Y>0) return 0;
        else{
            Lint res=(X/abs(X+Y)+1)*2-1;
            if(X%abs(X+Y)==0) res--;
            return res;
        }
    }
}

int main()
{
    Lint T1,T2,A1,A2,B1,B2; cin>>T1>>T2>>A1>>A2>>B1>>B2;
    Lint X=(A1-B1)*T1;
    Lint Y=(A2-B2)*T2;
    if(X+Y==0) cout<<"infinity"<<endl;
    else cout<<solve(X,Y)<<endl;
    return 0;
}