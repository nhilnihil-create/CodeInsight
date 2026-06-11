#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int h,w;
    while(cin>>h>>w)
    {
        if(w==0)return 0;
        REP(i,h)
        {
            REP(j,w)cout<<"#";
            cout<<endl;
        }
        cout<<endl;
    }
}

