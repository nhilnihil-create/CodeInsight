#include<bits/stdc++.h>
using namespace std;

int main() 
{
    long N,K;
    cin>>N>>K;

    vector<long>H;
    for (long i = 0; i < N; i++)
    {
        int h;
        cin>>h;
        H.push_back(h);
    }
    
    sort(H.begin(),H.end());

    while (K>0&&!H.empty())
    {
        H.pop_back();
        --K;
    }
    

    long ans=0;
    for (auto&h:H)
    {
        ans+=h;
    }
    

    cout<<ans<<endl;

    return 0;
}
