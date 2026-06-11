//SAIKH SERAJ FAHIM, CSE-19-HSTU, BANGLADESH.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int n,k,i,a,count=0;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    for(i=0; i<n; i++)
    {
        if(v[i]>=k)
            count++;
    }
    cout<<count<<endl;
    return 0;
}