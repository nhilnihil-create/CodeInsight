#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
   cin>>n;
   int r;
       if(n>=400 && n<=599)
       r=8;
        if(n>=600 && n<=799)
       r=7;
       if(n>=800 && n<=999)
       r=6;
        if(n>=1000 && 1199)
       r=5;
        if(n>=1200 && n<=1399)
       r=4;
        if(n>=1400 && n<=1599)
       r=3;
        if(n>=1600 && n<=1799 )
       r=2;
       if(n>=1800 && n<=1999)
       r=1;
       cout<<r<<"\n";
    return 0;
}
