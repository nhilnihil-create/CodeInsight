#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli a,b,c;
    cin>>a>>b>>c;
    if((a==b && (c!=a || c!=b))||(b==c && (a!=c || a!=b))||(a==c && (b!=a || b!=c)))
    cout<<"Yes"<<"\n";
    else
    cout<<"No"<<"\n";
}
    
    
    