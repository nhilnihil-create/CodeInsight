#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A,A+n);
    int ans=0;
    for(int i=0;i<k;i++)
        ans+=A[i];
        cout<<ans<<endl;
    return 0;
}
