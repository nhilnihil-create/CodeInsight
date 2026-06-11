#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n,i,count=0;
    cin>>n;
    vector<string> v1(n);
    map<string,ll> map1;
    for(i=0;i<n;i++)
    {
        cin>>v1[i];
        sort(v1[i].begin(),v1[i].end());
        map1[v1[i]]++;
    }
    for(auto x: map1)
    {
        if(x.second)
        {
            //cout<<x.second;
            count+=x.second*(x.second-1)/2;
        }
    }
    cout<<count;
    return 0;
}
