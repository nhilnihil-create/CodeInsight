#include<bits/stdc++.h>
#define ull unsigned long long
# define ll long long
# define mod 1000000007LL 
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    priority_queue<ll>ans;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    ans.push(arr[i]);
    }
    ll temp=0;
    while(k--)
    {
        temp=ans.top();
        temp=temp/2;
        ans.pop();
        ans.push(temp); 
    }
    ll sum=0;
    while(ans.size()!=0)
    {
        temp=ans.top();
        ans.pop();
        sum+=temp;
    }
    cout<<sum;


    
    return 0;
}