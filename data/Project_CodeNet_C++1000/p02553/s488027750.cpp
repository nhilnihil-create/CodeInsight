#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
#define ll long long

ll t1,t2,t3,t4;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    t1 = a*c;
    t2 = a*d;
    t3 = b*c;
    t4 = b*d;
    //cout<<t1;
    //cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<endl;
    ll t;

    if(t1<t2){
        t = t2;
    }
    else t = t1;

    if(t<t3)
        t = t3;

    if(t<t4)
        t = t4;

    cout<<t<<endl;
    return 0;
}

