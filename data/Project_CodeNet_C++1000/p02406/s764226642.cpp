#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

bool f(int x)
{
    if(x==0)return 0;
    if(x%10==3)return 1;
    else f(x/=10);
}

int main()
{
    int n;
    cin>>n;
    rep(i,1,n+1)
    {
        if(i%3==0)cout<<" "<<i;
        else if(f(i)==1)cout<<" "<<i;
    }
    cout<<endl;
}
