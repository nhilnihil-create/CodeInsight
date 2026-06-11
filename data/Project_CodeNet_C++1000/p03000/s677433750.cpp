#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int N,X;
    cin>>N>>X;
    vector<int>D(N+2),L;
    for (int i = 0; i < N; i++)
    {
        int l;
        cin>>l;
        L.push_back(l);
    }
    D.push_back(0);
    for (int i = 1; i < N+2; i++)
    {
        D[i]=D[i-1]+L[i-1];
    }
 
    auto it = upper_bound(D.begin(),D.end(),X);
    if(it==D.end())
    {
        cout<<N+1<<endl;
        return 0;
    }
 
    auto ans=distance(D.begin(),it);
    cout<<ans<<endl;
    
    return 0;   
}