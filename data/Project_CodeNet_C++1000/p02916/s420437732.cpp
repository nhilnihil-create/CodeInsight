#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll n,item,temp,ans=0;
    vector<ll>A;
    vector<ll>B;
    vector<ll>C;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>item;
        item--;
        A.push_back(item);
    }
    for(int i=0;i<n;i++)
    {
        cin>>item;
        B.push_back(item);
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>item;
        C.push_back(item);
    }
    for(int i=0;i<n;i++)
    {
        ans+=B[A[i]];
        if(i==0)
            continue;
        if(A[i-1]<n-1 && A[i-1]+1==A[i])
        {
          ans+=C[A[i-1]];
        }

    }
    cout<<ans<<endl;
    return 0;
}
