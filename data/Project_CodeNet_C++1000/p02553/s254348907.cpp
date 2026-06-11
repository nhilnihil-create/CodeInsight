#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(max(a*c,a*d),max(b*c,b*d));
}
