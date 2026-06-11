#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int Max = -1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        Max = max(Max,arr[i]);
    }
    vector<int> sieve(Max+1,0);
    for(int i=0;i<n;i++)
    {
        int curr = arr[i];
        for(int j=curr;j<=Max;j+=curr)
        {
            sieve[j]++;
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(sieve[arr[i]]==1)
            cnt++;
    }
    cout<<cnt;
}
