#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arra[n+5];
    for(int i=1; i<=n; i++)
        cin>>arra[i];
    int x=1;
    vector<ll>vec,ans;
    vec.push_back(1);
    int idx;
    for(int i=1; i<=m; i++)
    {

        ll y=x;
        x=arra[x];
        arra[y]=-1;
        if(arra[x]==-1)
        {
           for(int i=0;i<vec.size();i++) {
              if(vec[i]==x) {
                for(int j=i;j<vec.size();j++) {
                    ans.push_back(vec[j]);
                }

                break;

              }
           }
            break;
        }
        vec.push_back(x);
    }


    /// cout<<vec.size()<<endl;
    ll dx=vec.size()-1;
    m-=dx;
  ///  cout<<m<<endl;
    if(m<=0)
    {
        cout<<vec[dx]<<endl;
    }
    else
    {
        ll fx=ans.size();
        ll mx=m%fx;
        if(mx==0) {
            mx=fx;
        }

        cout<<ans[mx-1]<<endl;

    }



}
