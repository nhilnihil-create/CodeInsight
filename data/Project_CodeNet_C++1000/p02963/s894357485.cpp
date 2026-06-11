#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t S; cin>>S;

    int64_t x1=0,y1=0,x2=1,y2=1e9,x,y;
    // S=1e9*x-y
    x=S/y2+(S%y2>0);
    if(S%y2) y=y2-S%y2;
    else y=0;

    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x<<" "<<y<<endl;
    cerr<<abs(x*y2-x2*y)<<endl;
}