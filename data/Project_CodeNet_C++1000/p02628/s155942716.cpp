#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto& i:arr)
    cin>>i;
    ll ans=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<k;i++)
    ans+=arr[i];
    cout<<ans<<endl; 
}
