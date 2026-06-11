
/**Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
set<long long>st,stt;
set<long long>::iterator it,jt;
vector<long long>v;
long long x[200005];
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        v.push_back(a);
        x[a]=i;
    }
    st.insert(x[n]);
    stt.insert(-1*x[n]);
    for(i=n-1; i>0; i--)
    {
        d=INT_MAX;
        e=INT_MAX;
        p=INT_MAX;
        q=INT_MAX;
        it=st.lower_bound(x[i]);
        if(it==st.end())
            d=n+1;
        else
        {
            d=*it;
            it=st.upper_bound(d);
            if(it==st.end())
                e=n;
            else
                e=*it-1;
        }
        it=stt.lower_bound(-1*x[i]);
        if(it==stt.end())
            p=0;
        else
        {
            p=-1*(*it);
            it=stt.upper_bound((*it));
            if(it==stt.end())
                q=1;
            else
                q=-1*(*it)+1;
        }
        if(e==INT_MAX)
            e=d;
        if(q==INT_MAX)
            q=p;
        if(e>n)
            e--;
        if(q<1)
            q++;
        f+=i*(x[i]-p)*(e-d+1);
        f+=i*(p-q+1)*(d-x[i]);
        st.insert(x[i]);
        stt.insert(-x[i]);


    }
    cout<<f<<'\n';
    return 0;
}
