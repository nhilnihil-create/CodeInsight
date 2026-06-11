#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll n,m;
    cin>>n>>m;
    ll dif=m-n;
    if(dif<2019)
    {
        ll l=INT_MAX;
        for(ll i=n;i<m;i++){
         {
        for(int j=i+1;j<=m;j++)
        {
            ll tmp= (i*j)%2019;
            l=min(tmp,l);
        }
        }
    }
      cout<<l;
    }
    else{
        cout<<"0";
    }
}
