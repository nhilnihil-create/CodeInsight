#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N=2e5+9;
ll mark[N];
int main()
{
    FASTINOUT;
    ll x,d,a,hit=0,ans=0;
    cin>>x>>d>>a;
    d*=2;
    vector<pair<ll,ll>>v(x);
    for (int i=0;i<x;i++)
        cin>>v[i].first>>v[i].second;
        sort(v.begin(),v.end());
    for (int i=0;i<x;i++){
        v[i].second-=hit;
        if (v[i].second>0){
            ll need =(v[i].second+a-1)/a;
            ans+=need;
            hit+=need*a;
            ll l=i,r=x-1,mid;
            while (l<=r){
                mid=(l+r)/2;
                if (v[i].first+d>=v[mid].first)
                    l=mid+1;
                else
                    r=mid-1;
            }
            l--;
           // cout<<"l = "<<l<<endl;
            mark[l]+=need*a;
        }
        hit-=mark[i];
    }
    cout<<ans;
    return 0;
}
