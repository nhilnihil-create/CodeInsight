#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;

int main()
{

    ll t,n,m,f,a,b,c,l,r,q,k,x,y,z,ans,mn,mx,sum=0;
    string exp;
    cin>>n>>exp;

    char ch='#';
    c=0;

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]!=ch)
        {
            ch = exp[i];
            c++;
        }

    }
    cout<<c<<endl;


}
