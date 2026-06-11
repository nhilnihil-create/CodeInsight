#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    set<ll> st,st1;
    for(int i = 0 ; i < n; i++)
    {
        ll x,y;
        cin>>x>>y;
        st.insert(x+y);
        st1.insert(x-y);
       // cout<<(x+y)<<" "<<(x-y)<<endl;
    }
    ll fst=abs(*st.rbegin()-*st.begin());
    ll scnd=abs(*st1.rbegin()-*st1.begin());
    cout<<max(fst,scnd)<<endl;
    return 0;
}
