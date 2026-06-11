//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define mod 1000000007
#define endl '\n'
typedef long long int ll ;
using namespace std;
ll n=0;
vector<ll> v;
ll pre[500007];
ll answer_max_operations(ll k)
{
    ll left=0; ll right=n/k;
    while(true)
    {
        ll mid= (left+right)/2;
        int idx=lower_bound(v.begin(),v.end(),mid)-v.begin();
        ll val=v.size()-idx;
        if(idx!=0) val+=pre[idx-1]/mid;
        if(val>=k) left=mid;
        else right=mid;
        if(right-left<=1) break;
    }
    int idx=lower_bound(v.begin(),v.end(),right)-v.begin();
    ll val=v.size()-idx;
    if(idx!=0) val+=pre[idx-1]/right;
    if(val>=k) return right;
    else return left;
}
int main()
{
    cin>>n;
    map<ll,ll> mp;
    ll a; 
    for(int i=1;i<=n;i++){
        cin>>a;
        mp[a]++;
    }
    for(auto it= mp.begin();it!=mp.end();it++){
        v.push_back((ll)it->second);
    }
    sort(v.begin(),v.end());
    pre[0]=v[0];
    for(int i=1;i<v.size();i++) pre[i]=pre[i-1]+v[i];
    // for(int i=0;i<v.size();i++) cout<<pre[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<answer_max_operations(i)<<endl;
    }
    
    
}




