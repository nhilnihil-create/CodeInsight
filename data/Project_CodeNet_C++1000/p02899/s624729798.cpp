#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    map<int,int>order;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        order[arr[i]]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<order[i]<<" ";
    }
    
}