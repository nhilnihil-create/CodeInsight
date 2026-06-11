#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    long long int n,m,ans=0;
    cin>>n>>m;
    if(n==1 && m==1)
    {
        cout<<"0";
    }
    else
    {
        if(n>=2)
        {
            long long tm= n*(n-1);
            tm/=2;
            ans+=tm;
        }
        if(m>=2)
        {
            long long int tm= m*(m-1);
            tm/=2;
            ans+=tm;
        }
        cout<<ans;
    }
}
