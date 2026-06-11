//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll n,x,i,j;
    cin>>n;
    set<ll>st;
    for( i=0; i<n; i++)
    {
        cin>>x;
        st.insert(x);
    }
    if(st.size()==n)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}



