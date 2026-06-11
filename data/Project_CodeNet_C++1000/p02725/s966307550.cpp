#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    int k,n;
    cin>>k>>n;
    vector<int>arr(n);
    for(auto& i:arr)
    cin>>i;
    vector<int>dis;
    for(int i=0;i<n-1;i++)
    dis.push_back(arr[i+1]-arr[i]);
    dis.push_back(arr[0]+(k-arr.back()));
    //take n-1 elements 
    //how??
    int sum=0;
    for(auto i:dis)
    sum+=i;
    int ans=k;
    for(int i=0;i<(int)dis.size();i++)
    ans=min(ans,sum-dis[i]);
    cout<<ans<<endl;
}
