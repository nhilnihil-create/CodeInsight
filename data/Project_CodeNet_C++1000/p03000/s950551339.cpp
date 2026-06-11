#include<bits/stdc++.h>
#include<vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main()
{
    fastio;
    int i,n,input,x,count=0;
    cin>>n>>x;
    vector <int> v;
    vector <int> arr;
    arr.push_back(0);
    for (i=0;i<n;i++)
    {
        cin>>input;
        v.push_back(input);
    }
    for (i=0;i<n;i++) 
        arr.push_back(arr[i] + v[i]);
    for (i=0;i<n+1;i++)
    {
        if (arr[i]<=x)
            count++;
    }
    cout<<count<<endl;
}