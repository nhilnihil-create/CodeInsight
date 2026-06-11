#include <bits/stdc++.h>
using namespace std;


int main()
{

    long long a,b,c,d,x,y,p,q;
    cin>>a>>b>>c>>d;
    x=a*c;
    y=a*d;
    p=b*c;
    q=b*d;
    cout<<max(x,max(y,max(p,q)))<<endl;

    return 0;
}
