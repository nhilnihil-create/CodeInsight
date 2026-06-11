#define inf 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define m_p  make_pair
#define ull unsigned long long
#define spd  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ll n,i,sum=0;

    cin>>n;
    vector<ll>v(n);

    for(i=0;i<n;i++)
    {
      cin>>v[i];
    }

    for(i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            sum+=(v[i]-v[i+1]);
            v[i+1] = v[i];
        }
    }

    cout<<sum<<endl;
}
