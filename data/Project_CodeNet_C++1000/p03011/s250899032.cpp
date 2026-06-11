#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int p,q,r;
    cin>>p>>q>>r;
    cout<<min((p+q),min((p+r),(q+r)));
    nl;
    return 0;
}
