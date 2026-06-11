#include<iostream>
#include<queue>
#include<algorithm>
#include<numeric>
#include<string>
#include<map>
#include<bitset>

using namespace std;
using int_greater_PQ = priority_queue<int,vector<int>,greater<int>>;


int main() 
{
    int N,K;
    cin>>N>>K;

    vector<int>H;
    for(int i=0;i<N;++i)
    {
        int h;
        cin>>h;
        H.push_back(h);
    }

    int ans=0;
    for(const auto& h:H)
    {
        if(h>=K)
        {
            ++ans;
        }
    }

    cout<<ans<<endl;
    return 0;
}
