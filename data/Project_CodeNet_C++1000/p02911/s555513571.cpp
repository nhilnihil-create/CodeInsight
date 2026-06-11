#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,q;
    cin>>n>>k>>q;
    long long int a[q],score[n],answer[n];
    for(int i=0;i<n;i++)
    {
        score[i]=k;
        answer[i]=q;
    }
    for(int i=0;i<q;i++)
    {
        cin>>a[i];
        a[i]--;
        answer[a[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        score[i]=score[i]-answer[i];
        if(score[i]>0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}