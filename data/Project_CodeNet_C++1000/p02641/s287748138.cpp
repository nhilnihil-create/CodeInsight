#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for0(n) for(i=0; i<(n); i++)
#define for1(n) for(i=1; i<=(n); i++)


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _,i,j,n,a,b,e,k,u,t,x=1,m,y,q,f=1,c=0,d=0,l,p,z,o,r,g;
    string ss,s;
    cin>>x>>n;
    set<ll> st;
    for0(n)
    {
        cin>>a;
        st.insert(a);
    }
    y=st.size();
    a=b=x;
    while(1)
    {
        st.insert(a);
        if(y<st.size())
        {
            cout<<a<<endl;
            break;
        }
        st.insert(b);
        if(y<st.size())
        {
            cout<<b<<endl;
            break;
        }
        a--;b++;
    }
}

