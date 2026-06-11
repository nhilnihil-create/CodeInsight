#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll comb(ll n,ll r)
{
    if (n==1) return 1;
    if (r == 0 || r == n) return (1);
    else if (r == 1) return (n);
    return (comb(n - 1, r - 1) + comb(n - 1, r));
}

int main()
{
    ll N;
    cin >> N;
    map<string,ll> dic;
    for(int i=0;i<N;i++)
    {
        string s;cin>>s;
        sort(s.begin(),s.end());
        dic[s]++;
    }
    ll res=0;
    for(auto it=dic.begin();it!=dic.end();it++)
    {
        ll count=it->second;
        if(1<count)res+=comb(count,2);
    }
    cout<<res; 
    return 0;
}