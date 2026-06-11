#include <bits/stdc++.h> 
using namespace std; 

#define FileIO freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);  ios_base::sync_with_stdio(0);
#define IO ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0); 
#define ll long long
#define endl "\n"
#define mod 1000000007

int main()
{
    IO;
    set<int> out;
    for(int i = -3; i <= 200; i++)
    {
        out.insert(i);
    }
    int n,x;
    cin>>x>>n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        out.erase(a[i]);
    }
    n = out.size();
    int arr[n]={};
    int j = 0;
    for(int i : out)
    {
        arr[j++] = i;
    }
    int idx[3]={};
    idx[0] = lower_bound(arr, arr+n, x) - arr;
    idx[1] = idx[0] + 1;
    idx[2] = idx[0] - 1;
    
    int diff[3]={};
    diff[0] = abs(x - arr[idx[0]]);
    diff[1] = abs(x - arr[idx[1]]);
    diff[2] = abs(x - arr[idx[2]]);

    int ans = arr[idx[0]], d = INT_MAX;
    j = 0;
    for(int i : diff)
    {
        if(i < d)
        {
            d = i;
            ans = arr[idx[j]];
        }
        if(i == d)
        {
            ans = min(arr[idx[j]], ans);
        }
        j++;
    }

    cout<<ans<<endl;
    
    return 0;
}