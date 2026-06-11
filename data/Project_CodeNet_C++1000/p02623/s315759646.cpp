#include<bits/stdc++.h>
using namespace std;
int Bin_Search(vector<long long> &ans,long long k)
{
    int n = ans.size();
    int lo = 0;
    int hi = n-1;
    int sol = -1;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(ans[mid]<=k)
        {
            sol = mid;
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return sol+1;
}
int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long> A(n);
    vector<long long> B(m);
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<m;i++)
        cin>>B[i];
    vector<long long> pref_A(n);
    vector<long long> pref_B(m);
    pref_A[0] = A[0];
    pref_B[0] = B[0];
    for(int i=1;i<n;i++)
    {
        pref_A[i] = pref_A[i-1] + A[i];
    }
    for(int i=1;i<m;i++)
    {
        pref_B[i] = pref_B[i-1] + B[i];
    }
    int ans = Bin_Search(pref_B,k);
    for(int i=0;i<n;i++)
    {
        if(pref_A[i]>k)
        {
            break;
        }
        ans = max(ans,i+1+Bin_Search(pref_B,k-pref_A[i]));
    }
    cout<<ans<<endl;
}
