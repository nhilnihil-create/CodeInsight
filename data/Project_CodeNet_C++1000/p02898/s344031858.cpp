#include<bits/stdc++.h>
using namespace std;
int odd(int n, int k, int a[])
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i]>=k)
            count++;
    }
    return count;
}
int main()
{
    int n,k,res,a[100000];
    cin>>n>>k;
    for(int i = 0;i<n;i++)
        cin>>a[i];
    res = odd(n,k,a);
    cout<<res;
    return 0;
}