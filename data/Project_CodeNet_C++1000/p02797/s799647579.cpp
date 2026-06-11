#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()  {
    ll N,K,S,val=1e9;
    cin>>N>>K>>S;
    for(ll i=0;i<N;i++)
    {
        if(i<K)
            cout<<S<<" ";
        else
        {
            if(S<1e9)
                cout<<S+1<<" ";
            else
                cout<<"1 ";
        }
    }
    return 0;
}
