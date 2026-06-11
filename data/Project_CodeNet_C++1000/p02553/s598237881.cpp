#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long  a,b,c,d,m,n,s,t;
    cin>>a>>b>>c>>d;
    m=a*d;
    n=a*c;
    s=b*c;
    t=b*d;
   // cout<<n<<endl;
    cout<<max(m,max(n,max(s,t)))<<endl;
    return 0;
}
