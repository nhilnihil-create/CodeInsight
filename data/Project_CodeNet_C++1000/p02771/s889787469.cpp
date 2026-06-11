#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
          ll n,c=0;
          set<ll>s;
          for(ll i=0;i<3;i++)
          {
                    cin>>n;
                    s.insert(n);
          }
          if(s.size()==2)
                    cout<<"Yes";
          else cout<<"No";
}
