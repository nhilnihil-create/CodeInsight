#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int a,b;
    cin >> a>>b;

    int ans = 0;
    if(a==1) ans+=300000;
    if(a==2) ans+=200000;
    if(a==3) ans+=100000;
    if(b==1) ans+=300000;
    if(b==2) ans+=200000;
    if(b==3) ans+=100000;
    if(a==1&&b==1) ans+=400000;

    cout << ans<< endl;

   return 0;
}
