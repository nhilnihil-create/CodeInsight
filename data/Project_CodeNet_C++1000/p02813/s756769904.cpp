#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n;
    cin>>n;
    vector<int> p(n),q(n),data(n);
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>q[i];
    rep(i,n) data[i]=i+1;
    map<vector<int>,int> mp;
    do
    {
        mp[data]=mp.size();
    }while(next_permutation(data.begin(),data.end()));
    cout<<abs(mp[p]-mp[q]);
}