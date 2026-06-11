   //\\========================================//\\
  //  \\            @SHIMOL NAHA              //  \\
 // SN \\           @worst_coder             // SN \\
//======\\==================================//======\\

#include<bits/stdc++.h>
#define ll long long int
#define pp push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(9);
    ll n,m,i,p,k,l,q,r,j,x,y,t;
    cin>>l;
    k=0;
    for(i=1; i<l; i++)
    {
        p=l/i;
        if(l%i!=0)
        {
            k+=p;
        }
        else k+=p-1;
    }
    cout<<k;
}
