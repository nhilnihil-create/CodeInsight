#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;

    vector<int>P;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin>>p;
        P.push_back(p);
    }
    
    int ans=0;
    for (int i = 1; i < n-1; i++)
    {
        auto p=minmax({P[i-1],P[i],P[i+1]});
        if(p.first!=P[i]&&p.second!=P[i])
        {
            ++ans;
        }
    }
    

    cout<<ans<<endl;

    return 0;
}